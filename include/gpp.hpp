#ifndef smv_gpp_gpp_hpp
#define smv_gpp_gpp_hpp

#include "parser_antlr4.h"
#include "util.hpp"
// #include <unordered_map>

namespace gpp {
std::unique_ptr<parser_antlr4> FrontendParse(const std::string &code);

struct BytecodeEmitter;
struct ExecutionFrame;
struct VerboseInstruction;
struct Instruction;
struct Word;
enum Macro : u8;
enum Command : u8;

struct Machine;
struct Vec3D;
struct Vec2D;
struct Tool;
// TODO something like using gpp::ToolTable = std::unordered_map<int, Tool>;
enum SpindleDirection : i8;
enum Unit : u8;
enum DistanceMode : u8;
enum Plane : u8;
enum FeedMode : u8;
enum SpindleMode : u8;
enum RetractMode : u8;
enum MotionControlMode : u8;
} // namespace gpp

#ifndef private_prod
#define private_prod private
#endif

#endif