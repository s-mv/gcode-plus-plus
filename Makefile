TITLE    = gcode++
CXX     ?= g++
OBJECTS  = build/util.o build/frontend.o build/bytecode.o build/machine.o

### replace with your path ###
ANTLR4_LIB     = /usr/local/lib/
ANTLR4_INCLUDE = /usr/local/include/antlr4-runtime/

ANTLR_OBJECTS = build/lexer_antlr4.o build/parser_antlr4.o build/parser_antlr4BaseVisitor.o

### testing with catch2 ###
TEST_LDFLAGS = $(LDFLAGS) -lCatch2Main -lCatch2
TEST_OBJECTS = build/example_test.o

CXXFLAGS = -std=c++17 -g -I include/ -I antlr4/gen/ -I $(ANTLR4_INCLUDE) -I /usr/include/catch2
LDFLAGS  = -L $(ANTLR4_LIB) -lantlr4-runtime

TEST_OBJECTS = build/example_test.o

.PHONY: all dev clean new antlr

default: dev

test: $(OBJECTS) $(ANTLR_OBJECTS) $(TEST_OBJECTS)
	@$(CXX) $(TEST_OBJECTS) $(OBJECTS) $(ANTLR_OBJECTS) -o build/test_example $(CXXFLAGS) $(TEST_LDFLAGS)
	@./build/test_example

antlr:
	@cd antlr4 && antlr4 -Dlanguage=Cpp -visitor -o gen lexer_antlr4.g4 parser_antlr4.g4

dev: $(OBJECTS) $(ANTLR_OBJECTS)
	@$(CXX) main.cpp $(OBJECTS) $(ANTLR_OBJECTS) -o build/$(TITLE) $(CXXFLAGS) $(LDFLAGS)

build/parser_antlr4BaseVisitor.o: antlr4/gen/parser_antlr4BaseVisitor.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%_antlr4.o: antlr4/gen/%_antlr4.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%_test.o: tests/%.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%.o: src/%.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@rm -rf ${OBJECTS} $(ANTLR_OBJECTS) build/test_example.o build/test_example antlr4/gen/* build/$(TITLE)

# helper to make new source-header pairs
name ?= newfile
new:
	@printf "#ifndef smv_gcodepp_$(name)_hpp\n#define smv_gcodepp_$(name)_hpp\n\n\n#endif" > include/$(name).hpp
	@printf "#include \"$(name).hpp\"" > src/$(name).cpp
