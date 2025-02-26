TITLE=gcode++
CC ?= gcc
OBJECTS = build/util.o build/lexer.o build/parser.o
CLFAGS = -std=c99 -g

.PHONY: dev clean

default: dev

dev: $(OBJECTS)
	@$(CC) main.c $(OBJECTS) -I include/ -o build/$(TITLE)

build/%.o: src/%.c
	@$(CC) $< -I include/ $(CLFAGS) -o $@ -c

clean:
	@rm -rf ${OBJECTS}

# helper to make new source-header pairs
name = newfile
new:
	@printf "#ifndef smv_gcodepp_$(name)_h\n#define smv_gcodepp_$(name)_h\n\n\n#endif" > include/$(name).h
	@printf "#include \"$(name).h\"" > src/$(name).c
