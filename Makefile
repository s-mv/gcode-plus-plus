TITLE    = gcode++
CXX     ?= g++
OBJECTS  = build/util.o build/frontend.o build/bytecode.o \
           build/expression.o build/machine.o build/line.o \
           build/instructions.o build/canvas.o
EXTERN   = extern/

### replace with your path(s) ###
ANTLR4_LIB     = $(EXTERN)antlr4/lib/
ANTLR4_INCLUDE = -I $(EXTERN)antlr4/gen/ -I $(EXTERN)antlr4/include/
ANTLR4_OBJECTS  = build/lexer_antlr4.o build/parser_antlr4.o \
                 build/parser_antlr4BaseVisitor.o

STB_INCLUDE = -I $(EXTERN)stb/

### testing with doctest ###
TEST_TYPE    = unit
TEST_INCLUDE = -I $(EXTERN)doctest/
TEST_TARGETS = unit regression

# UNIT_TEST_FILES = tests/unit.cpp tests/gcode.cpp

UNIT_TEST_FILES = tests/unit.cpp tests/testutil.cpp \
				tests/calculation.cpp tests/extended_grammar.cpp \
				tests/gcode.cpp tests/mcode.cpp tests/edge_cases.cpp \
				tests/g93_97.cpp tests/g81_83.cpp tests/g84_86.cpp

LDFLAGS  = $(ANTLR4_LIB)libantlr4-runtime.a
CXXFLAGS = -std=c++17 -g -I include/ $(ANTLR4_INCLUDE) $(STB_INCLUDE)

.PHONY: all dev clean new antlr test regression unit

default: dev

test:
	@echo "Working on $(TEST_TYPE) tests."
	@$(MAKE) --no-print-directory $(TEST_TYPE)

unit: $(OBJECTS) $(ANTLR4_OBJECTS) $(UNIT_TEST_FILES)
	@echo "Building unit tests..."
	@$(CXX) $(UNIT_TEST_FILES) \
		$(OBJECTS) $(ANTLR4_OBJECTS) -o build/unit $(CXXFLAGS) $(LDFLAGS) $(TEST_INCLUDE)
	@echo "Running unit tests..."
	@./build/unit

regression: $(OBJECTS) $(ANTLR4_OBJECTS)
	@echo "Building regression tests..."
	@$(CXX) tests/regression.cpp $(TEST_INCLUDE) \
		$(OBJECTS) $(ANTLR4_OBJECTS) -o build/regression $(CXXFLAGS) $(LDFLAGS)
	@./build/regression -s

antlr:
	@cd antlr4 && java -jar ../$(EXTERN)antlr4/antlr-4.13.2-complete.jar -Dlanguage=Cpp \
		-visitor -o ../extern/antlr4/gen lexer_antlr4.g4 parser_antlr4.g4

dev: $(OBJECTS) $(ANTLR4_OBJECTS)
	@$(CXX) main.cpp $(OBJECTS) $(ANTLR4_OBJECTS) -o build/$(TITLE) \
		$(CXXFLAGS) $(LDFLAGS)

DIR = /usr/local/bin
install: $(OBJECTS) $(ANTLR4_OBJECTS)
	@sudo $(CXX) main.cpp $(OBJECTS) $(ANTLR4_OBJECTS) -o $(DIR)/$(TITLE) \
		$(CXXFLAGS) $(LDFLAGS)

build/parser_antlr4BaseVisitor.o: extern/antlr4/gen/parser_antlr4BaseVisitor.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%_antlr4.o: extern/antlr4/gen/%_antlr4.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

build/%.o: src/%.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@rm -rf ${OBJECTS} $(ANTLR4_OBJECTS) build/unit.o build/unit \
		build/regression build/regression.o $(EXTERN)antlr4/gen/* build/$(TITLE)

# helper to make new source-header pairs
name ?= newfile
new:
	@printf "#ifndef smv_gpp_$(name)_hpp\n" > include/$(name).hpp
	@printf "#define smv_gpp_$(name)_hpp\n\n\n#endif\n" >> include/$(name).hpp
	@printf "#include \"$(name).hpp\"" > src/$(name).cpp
