# Architecture

This interpreter processes G-code in the following stages:

                          +-------------------+
                          |   std::string     |
                          |   Raw G-code      |
                          +-------------------+
                                    |
                                    v
                        +------------------------+
                        | FrontendParse(code)    |
                        | => ANTLR4 Lexer +      |
                        |    Parser              |
                        +------------------------+
                                    |
                                    v
                        +------------------------+
                        | BytecodeEmitter        |
                        |------------------------|
                        | - std::vector<Word>    |
                        | - std::queue<Instr>    |
                        | - ANTLR parser/lexer   |
                        | - Execution stack      |
                        | - Ref to Machine       |
                        +------------------------+
                                    |
                                    | emits
                                    |-----+
                                    v
                         +-----------------------+
                         |   Instruction Queue   |
                         +-----------------------+
                                    |
                                    v
                         +-----------------------+
                         | Machine               |
                         |-----------------------|
                         | - position: Vec3D     |
                         | - origin: Vec3D       |
                         | - unit, plane, mode   |
                         | - feedRate, spindle   |
                         | - handlers[]          |
                         | - canvasXY/YZ/XZ      |
                         +-----------------------+
                                    |
                         runs       |
                         +----------|
                                    v
               +----------------------------------------+
               | Motion + State Handlers                |
               |----------------------------------------|
               | move_linear() / move_rapid()           |
               | arc_feed(), dwell(), spindle_xxx()     |
               | set_feed_rate(), set_origin_offsets()  |
               | use_length_units(), select_plane(),... |
               +----------------------------------------+

## 1. Parsing

We use **ANTLR4** for lexing and parsing G-code. The grammar is split into:

- `lexer_antlr4.g4`: token definitions (`G`, `M`, numbers, comments, etc.)
- `parser_antlr4.g4`: G-code syntax (lines, expressions, blocks, etc.)

After parsing, we get a complete parse tree that preserves:
- Individual G/M-word commands
- Modal groups
- Parameters (`X`, `Y`, `F`, etc.)
- Control structures (future: loops, conditionals)

The entry point is:
```cpp
std::unique_ptr<parser_antlr4> FrontendParse(const std::string& code);
```

## 2. Instruction Generation (Visitor Pass)

We then walk the ANTLR parse tree using a custom visitor:
```cpp
class BytecodeEmitter : public parser_antlr4BaseVisitor
```

This converts each line/block into an internal Instruction object with:
- A command (`move_linear`, `move_rapid`, `set_feed_rate`, etc.).
- Arguments: an `arguments` vector of 64-bit float values.

The result is a list of typed, ready-to-process `Instruction`s. This pass
performs no side effects or state tracking.

## 3. Bytecode Queue
The `Instruction`s are stored in a queue inside BytecodeEmitter. This acts like
a lightweight bytecode representation of the G-code file.

The `Machine` reads from this queue one instruction at a time.

## 4. Execution (`Machine`)
The `gpp::Machine` struct represents the virtual CNC machine.

When an instruction is popped via `gpp::Machine::next()` the appropriate function handler is run and the machine state changes as per the instruction.

## 4.1/5. Rendering

The motion path is visualized by rendering onto three 2D planes: XY, YZ, and XZ.

These planes are rendered onto `output/canvas_XY.png`, `output/canvas_YZ.png`, and `output/canvas_XZ.png` if spindle direction isn't `off` (i.e. when the spindle is turning).
