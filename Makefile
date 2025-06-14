TITLE    = gcode++
CXX     ?= g++
OBJECTS  = build/util.o build/frontend.o build/bytecode.o \
           build/expression.o build/machine.o build/line.o \
					 build/instructions.o build/canvas.o
EXTERN   = extern/

### replace with your path ###
ANTLR4_LIB     = $(EXTERN)antlr4/lib/
ANTLR4_INCLUDE = -I $(EXTERN)antlr4/gen/ -I $(EXTERN)antlr4/include/
ANTLR_OBJECTS  = build/lexer_antlr4.o build/parser_antlr4.o \
                 build/parser_antlr4BaseVisitor.o

STB_INCLUDE = -I $(EXTERN)stb/

### testing with catch2 ###
TEST_TYPE    = unit
TEST_INCLUDE = -I $(EXTERN)catch2/
TEST_TARGETS = unit regression

LDFLAGS  = $(ANTLR4_LIB)libantlr4-runtime.a
CXXFLAGS = -std=c++17 -g -I include/ $(ANTLR4_INCLUDE) $(STB_INCLUDE)

.PHONY: all dev clean new antlr test regression unit

default: dev

test:
	@echo "Running $(TEST_TYPE) tests."
	@$(MAKE) --no-print-directory $(TEST_TYPE)

$(TEST_TARGETS): $(OBJECTS) $(ANTLR_OBJECTS)
$(TEST_TARGETS): %: tests/%.cpp
	@$(CXX) tests/$@.cpp $(TEST_INCLUDE) $(EXTERN)catch2/catch_amalgamated.cpp \
		$(OBJECTS) $(ANTLR_OBJECTS) -o build/$@ $(CXXFLAGS) $(LDFLAGS)
	@./build/$@ -s

antlr:
	@cd antlr4 && antlr4 -Dlanguage=Cpp -visitor -o ../extern/antlr4/gen \
		lexer_antlr4.g4 parser_antlr4.g4

dev: $(OBJECTS) $(ANTLR_OBJECTS)
	@$(CXX) main.cpp $(OBJECTS) $(ANTLR_OBJECTS) -o build/$(TITLE) \
		$(CXXFLAGS) $(LDFLAGS)

build/parser_antlr4BaseVisitor.o: extern/antlr4/gen/parser_antlr4BaseVisitor.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%_antlr4.o: extern/antlr4/gen/%_antlr4.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%.o: src/%.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@rm -rf ${OBJECTS} $(ANTLR_OBJECTS) build/unit.o build/unit \
		 build/regression build/regression.o $(EXTERN)antlr4/gen/* build/$(TITLE)

# helper to make new source-header pairs
name ?= newfile
new:
	@printf "#ifndef smv_gpp_$(name)_hpp\n" > include/$(name).hpp
	@printf "#define smv_gpp_$(name)_hpp\n\n\n#endif\n" >> include/$(name).hpp
	@printf "#include \"$(name).hpp\"" > src/$(name).cpp
