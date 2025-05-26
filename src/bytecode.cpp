#include "bytecode.hpp"

// helper function
std::string get_code_name(g_opcode code);

void g_bytecode_emitter::run(parser_antlr4::ProgramContext *context) {
  this->visitProgram(context);
}

antlrcpp::Any
g_bytecode_emitter::visitProgram(parser_antlr4::ProgramContext *context) {
  for (parser_antlr4::LineContext *line : context->line()) {
    visit(line);
  }
  return nullptr;
}

antlrcpp::Any
g_bytecode_emitter::visitLine(parser_antlr4::LineContext *context) {
  for (parser_antlr4::SegmentContext *segment : context->segment()) {
    visit(segment);
  }
  bytecode.push_back({.code = g_opcode::end_line});
  return nullptr;
}

antlrcpp::Any
g_bytecode_emitter::visitSegment(parser_antlr4::SegmentContext *context) {
  if (context->mid_line_word()) {
    visit(context->mid_line_word());
  } else if (context->parameter_setting()) {
    visit(context->parameter_setting());
  } else if (context->comment()) {
    visit(context->comment());
  }
  return nullptr;
}

antlrcpp::Any g_bytecode_emitter::visitMid_line_word(
    parser_antlr4::Mid_line_wordContext *context) {
  char letter = std::tolower(context->mid_line_letter()->getText().at(0));
  f64 value = std::any_cast<f64>(visit(context->real_value()));
  i64 value_asint = static_cast<i64>(value);

  switch (letter) {
  case 'g':
    switch (value_asint) {
    case 0:
      bytecode.push_back({.code = g_opcode::rapid_move});
      break;
    case 1:
      bytecode.push_back({.code = g_opcode::linear_move});
      break;
    default:
      // TODO: Handle other cases
      break;
    }
    break;

  case 'x':
    bytecode.push_back({.code = g_opcode::set_x});
    bytecode.push_back({.attr = value});
    break;

  case 'y':
    bytecode.push_back({.code = g_opcode::set_y});
    bytecode.push_back({.attr = value});
    break;

  case 'z':
    bytecode.push_back({.code = g_opcode::set_z});
    bytecode.push_back({.attr = value});
    break;

  case 'f':
    bytecode.push_back({.code = g_opcode::set_feedrate});
    bytecode.push_back({.attr = value});
    break;

  default:
    // TODO: Handle other cases
    break;
  }
  return nullptr;
}

antlrcpp::Any
g_bytecode_emitter::visitReal_value(parser_antlr4::Real_valueContext *context) {
  if (context->real_number()) {
    return visit(context->real_number());
  } else if (context->expression()) {
    return visit(context->expression());
  } else if (context->parameter_value()) {
    // TODO: Handle parameter_value
  } else if (context->unary_combo()) {
    // TODO: Handle unary_combo
  }
  return 0.0;
}

antlrcpp::Any g_bytecode_emitter::visitReal_number(
    parser_antlr4::Real_numberContext *context) {
  return std::stod(context->getText());
}

antlrcpp::Any
g_bytecode_emitter::visitComment(parser_antlr4::CommentContext *context) {
  std::string text = context->getText();
  std::cout << "Comment: " << text << std::endl;
  return nullptr;
}

void g_bytecode_emitter::print() {
  for (g_inst inst : bytecode) {
    std::string code = get_code_name(inst.code);
    if (code == "...") {
      std::cout << "ATTRIBUTE: " << inst.attr << "\n";
    } else
      std::cout << "OPERATION: " << code << "\n";
  }
}

std::string get_code_name(g_opcode code) {
  switch (code) {
  case g_opcode::linear_move:
    return "MOVE LINEAR";
  case g_opcode::rapid_move:
    return "RAPID MOVE";
  case g_opcode::set_feedrate:
    return "SET FEEDRATE";
  case g_opcode::set_x:
    return "SET X";
  case g_opcode::set_y:
    return "SET Y";
  case g_opcode::set_z:
    return "SET Z";
  default:
    return "...";
  }
}