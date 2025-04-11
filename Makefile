TITLE    = gcode++
CXX     ?= g++
OBJECTS  = build/util.o build/lexer.o build/parser.o

### replace with your path ###
ANTLR4_LIB     = /usr/local/lib/
ANTLR4_INCLUDE = /usr/local/include/antlr4-runtime/

CXXFLAGS = -std=c++17 -g -I include/ -I antlr4/gen/ -I $(ANTLR4_INCLUDE)
LDFLAGS  = -L $(ANTLR4_LIB) -lantlr4-runtime

.PHONY: all dev clean new

default: dev

dev: $(OBJECTS)
	@$(CXX) main.cpp $(OBJECTS) -o build/$(TITLE) $(CXXFLAGS) $(LDFLAGS)

build/%.o: src/%.cpp
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	@rm -rf ${OBJECTS} build/$(TITLE)

# helper to make new source-header pairs
name ?= newfile
new:
	@printf "#ifndef smv_gcodepp_$(name)_hpp\n#define smv_gcodepp_$(name)_hpp\n\n\n#endif" > include/$(name).hpp
	@printf "#include \"$(name).hpp\"" > src/$(name).cpp
