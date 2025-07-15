#include "antlr4-runtime.h"
#include "lexer_antlr4.h"
#include "parser_antlr4.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

using namespace antlr4;
using namespace antlr4::tree;

class TreePrinter {
private:
  std::string indent;

public:
  void printTree(ParseTree *tree, parser_antlr4 *parser, int depth = 0) {
    if (!tree)
      return;

    // Print current node
    for (int i = 0; i < depth; i++) {
      std::cout << "  ";
    }

    if (auto *ruleNode = dynamic_cast<RuleContext *>(tree)) {
      // Print rule name
      std::string ruleName = parser->getRuleNames()[ruleNode->getRuleIndex()];
      std::cout << ruleName;

      // If it's a terminal with text, show the text
      if (tree->children.size() == 1) {
        if (auto *terminal = dynamic_cast<TerminalNode *>(tree->children[0])) {
          std::string text = terminal->getText();
          if (!text.empty() && text != " " && text != "\n") {
            std::cout << " [" << text << "]";
          }
        }
      }
      std::cout << std::endl;
    } else if (auto *terminal = dynamic_cast<TerminalNode *>(tree)) {
      // Print terminal
      std::string text = terminal->getText();
      if (text == "\n") {
        std::cout << "\\n" << std::endl;
      } else if (text == " ") {
        std::cout << "SPACE" << std::endl;
      } else {
        std::cout << "'" << text << "'" << std::endl;
      }
    }

    // Print children recursively
    for (auto *child : tree->children) {
      printTree(child, parser, depth + 1);
    }
  }
};

class ErrorListener : public BaseErrorListener {
public:
  void syntaxError(Recognizer *recognizer, Token *offendingSymbol, size_t line,
                   size_t charPositionInLine, const std::string &msg,
                   std::exception_ptr e) override {
    std::cerr << "Syntax error at line " << line << ":" << charPositionInLine
              << " - " << msg << std::endl;
  }
};

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " <gcode_file>" << std::endl;
    std::cout << "   or: " << argv[0] << " -s \"<gcode_string>\"" << std::endl;
    return 1;
  }

  std::string input;

  if (std::string(argv[1]) == "-s") {
    if (argc < 3) {
      std::cerr << "Error: No string provided after -s" << std::endl;
      return 1;
    }
    input = argv[2];
  } else {
    // Read from file
    std::ifstream file(argv[1]);
    if (!file.is_open()) {
      std::cerr << "Error: Cannot open file " << argv[1] << std::endl;
      return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
      input += line + "\n";
    }
    file.close();
  }

  try {
    // Create input stream
    ANTLRInputStream inputStream(input);

    // Create lexer
    lexer_antlr4 lexer(&inputStream);

    // Create token stream
    CommonTokenStream tokens(&lexer);

    // Create parser
    parser_antlr4 parser(&tokens);

    // Add error listener
    ErrorListener errorListener;
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    // Parse starting from the 'block' rule
    auto *tree = parser.block();

    // Print the tree
    std::cout << "Parse Tree:" << std::endl;
    std::cout << "===========" << std::endl;

    TreePrinter printer;
    printer.printTree(tree, &parser);

    // Print some statistics
    std::cout << std::endl << "Statistics:" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "Tokens processed: " << tokens.size() << std::endl;
    std::cout << "Parser errors: " << parser.getNumberOfSyntaxErrors()
              << std::endl;

  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }

  return 0;
}

// Alternative version with more detailed tree information
class DetailedTreePrinter {
private:
  int nodeCount = 0;

public:
  void printDetailedTree(ParseTree *tree, parser_antlr4 *parser,
                         int depth = 0) {
    if (!tree)
      return;

    nodeCount++;

    // Print indentation
    for (int i = 0; i < depth; i++) {
      std::cout << "│   ";
    }

    if (depth > 0) {
      std::cout << "├── ";
    }

    if (auto *ruleNode = dynamic_cast<RuleContext *>(tree)) {
      // Print rule information
      std::string ruleName = parser->getRuleNames()[ruleNode->getRuleIndex()];
      std::cout << "[" << ruleName << "]";

      // Show rule index and context info
      std::cout << " (rule:" << ruleNode->getRuleIndex()
                << ", children:" << tree->children.size() << ")";

      // Show source interval
      if (ruleNode->start && ruleNode->stop) {
        std::cout << " <" << ruleNode->start->getStartIndex() << ".."
                  << ruleNode->stop->getStopIndex() << ">";
      }

      std::cout << std::endl;

    } else if (auto *terminal = dynamic_cast<TerminalNode *>(tree)) {
      // Print terminal information
      Token *token = terminal->getSymbol();
      std::string text = terminal->getText();

      std::cout << "\"" << text << "\"";
      std::cout << " (token:" << token->getType()
                << ", line:" << token->getLine()
                << ", pos:" << token->getCharPositionInLine() << ")";
      std::cout << std::endl;
    }

    // Print children
    for (size_t i = 0; i < tree->children.size(); i++) {
      printDetailedTree(tree->children[i], parser, depth + 1);
    }
  }

  int getNodeCount() const { return nodeCount; }
};

// Function to use the detailed printer
void printDetailedParseTree(const std::string &input) {
  ANTLRInputStream inputStream(input);
  lexer_antlr4 lexer(&inputStream);
  CommonTokenStream tokens(&lexer);
  parser_antlr4 parser(&tokens);

  ErrorListener errorListener;
  parser.removeErrorListeners();
  parser.addErrorListener(&errorListener);

  auto *tree = parser.block();

  std::cout << std::endl << "Detailed Parse Tree:" << std::endl;
  std::cout << "===================" << std::endl;

  DetailedTreePrinter detailedPrinter;
  detailedPrinter.printDetailedTree(tree, &parser);

  std::cout << std::endl
            << "Total nodes: " << detailedPrinter.getNodeCount() << std::endl;
}
