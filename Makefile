TITLE    = gcode++
CXX     ?= g++
OBJECTS  = build/util.o build/frontend.o build/bytecode.o build/machine.o

### replace with your path ###
ANTLR4_LIB     = /usr/local/lib/
ANTLR4_INCLUDE = /usr/local/include/antlr4-runtime/

ANTLR_OBJECTS = build/lexer_antlr4.o build/parser_antlr4.o build/parser_antlr4BaseVisitor.o

CXXFLAGS = -std=c++17 -g -I include/ -I antlr4/gen/ -I $(ANTLR4_INCLUDE)
LDFLAGS  = -L $(ANTLR4_LIB) -lantlr4-runtime

.PHONY: all dev clean new antlr

default: dev

antlr:
	@cd antlr4 && antlr4 -Dlanguage=Cpp -visitor -o gen lexer_antlr4.g4 parser_antlr4.g4

dev: $(OBJECTS) $(ANTLR_OBJECTS)
	@$(CXX) main.cpp $(OBJECTS) $(ANTLR_OBJECTS) -o build/$(TITLE) $(CXXFLAGS) $(LDFLAGS)

build/parser_antlr4BaseVisitor.o: antlr4/gen/parser_antlr4BaseVisitor.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%_antlr4.o: antlr4/gen/%_antlr4.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%.o: src/%.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@rm -rf ${OBJECTS} $(ANTLR_OBJECTS) antlr4/gen/* build/$(TITLE)

# helper to make new source-header pairs
name ?= newfile
new:
	@printf "#ifndef smv_gcodepp_$(name)_hpp\n#define smv_gcodepp_$(name)_hpp\n\n\n#endif" > include/$(name).hpp
	@printf "#include \"$(name).hpp\"" > src/$(name).cpp
