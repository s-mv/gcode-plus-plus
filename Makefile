TITLE=gcode++
CXX ?= g++
OBJECTS = build/util.o build/lexer.o build/parser.o
CLFAGS = -std=c++11 -g

.PHONY: dev clean

default: dev

dev: $(OBJECTS)
	@$(CXX) main.cpp $(OBJECTS) -I include/ -o build/$(TITLE) $(CLFAGS)

build/%.o: src/%.cpp
	@$(CXX) $< -I include/ $(CLFAGS) -o $@ -c

clean:
	@rm -rf ${OBJECTS}

# helper to make new source-header pairs
name = newfile
new:
	@printf "#ifndef smv_gcodepp_$(name)_hpp\n#define smv_gcodepp_$(name)_hpp\n\n\n#endif" > include/$(name).h
	@printf "#include \"$(name).h\"" > src/$(name).c
