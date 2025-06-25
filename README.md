# g-code++ - an extension of g-code (might rename later)

A lightweight G-code interpreter written in C++ inspired by the
[NIST rs274ngc interpreter](https://github.com/QGCoder/rs274ngc).

The output of the interpreter may be used to drive 3-axis machines.

## Documentation
- Architecture - [docs/ARCHITECTURE.md](/docs/ARCHITECTURE.md)
- Instructions - [docs/INSTRUCTIONS.md](/docs/INSTRUCTIONS.md)

## Build and Install

### Required tools:

- Any compiler for C++17 or later
- `make`

### Build

```
make antlr
make dev
./build/gcode++ <filename>
```

### Install

By default, `make install` builds and installs the binary into `/usr/local/bin`.

```
make install # optional: `DIR=/usr/bin` or something
gcode++ <filename>
```

### Test 
```
make test unit       # runs all unit tests
make test regression # regression tests
```

## Supported codes:

- **Motion**: `G0`, `G1`, `G2`, `G3`
- **Plane Select**: `G17`, `G18`, `G19`
- **Units**: `G20` (inches), `G21` (millimeters)
- **Positioning Modes**: `G90` (absolute), `G91` (relative)
- **Coordinate Offset**: `G92`
- **Spindle Control**: `M3`, `M4`, `M5`, `s<speed>`
- **Feedrate**: `F<feedrate>`
- More TODO...

## ANTLR4 Dependency

If you want to make changes to the [antlr grammar](/antlr4/), Java is required
since `make antlr` depends on Java. You'll have to run `make antlr` to test as
well as build the binary.
