#ifndef smv_gcodepp_gpp_hpp
#define smv_gcodepp_gpp_hpp

#include "parser_antlr4.h"
#include "util.hpp"

namespace gpp {
std::unique_ptr<parser_antlr4> FrontendParse(const std::string &code);

struct BytecodeEmitter;
struct ExecutionFrame;
struct Instruction;
struct Word;
enum Command : u8;

struct Machine;
struct Vec3D;
enum Unit : u8;
} // namespace gpp

#endif