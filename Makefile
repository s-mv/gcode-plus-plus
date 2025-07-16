STERPSRCS := emc/sterp/sterp.cc
USERSRCS += $(STERPSRCS)
TARGETS += ../lib/linuxcnc/sterp.so

THISDIR = $(CURDIR)/

TITLE    = gcode++
CXX     ?= g++
OBJECTS  = $(THISDIR)build/util.o $(THISDIR)build/frontend.o $(THISDIR)build/bytecode.o \
           $(THISDIR)build/expression.o $(THISDIR)build/machine.o $(THISDIR)build/line.o \
           $(THISDIR)build/instructions.o $(THISDIR)build/canvas.o
EXTERN   = $(THISDIR)extern/

ANTLR4_LIB     = $(EXTERN)antlr4/lib/
ANTLR4_INCLUDE = -I $(EXTERN)antlr4/gen/ -I $(EXTERN)antlr4/include/
ANTLR4_OBJECTS  = $(THISDIR)build/lexer_antlr4.o $(THISDIR)build/parser_antlr4.o \
                 $(THISDIR)build/parser_antlr4BaseVisitor.o

STB_INCLUDE = -I $(EXTERN)stb/

TEST_TYPE    = unit
TEST_INCLUDE = -I $(EXTERN)doctest/
TEST_TARGETS = unit regression

UNIT_TEST_FILES = tests/unit.cpp tests/testutil.cpp \
                tests/calculation.cpp tests/extended_grammar.cpp \
                tests/gcode.cpp tests/mcode.cpp tests/edge_cases.cpp \
                tests/g93_97.cpp tests/g81_83.cpp tests/g84_86.cpp \
                tests/g87_89.cpp tests/errors.cpp

LDFLAGS  = -L $(ANTLR4_LIB) -lantlr4-runtime
CXXFLAGS = -std=c++17 -fPIC -g -I $(THISDIR)include/ $(ANTLR4_INCLUDE) $(STB_INCLUDE)
CXXFLAGS += -Wno-overloaded-virtual -Wno-reorder -Wno-sign-compare -Wno-unused-variable 

.PHONY: all dev clean new antlr test regression unit install

default: linuxcnc

$(call TOOBJSDEPS, $(STERPSRCS)) : EXTRAFLAGS=-fPIC

../lib/linuxcnc/sterp.so: $(ANTLR4_OBJECTS) $(OBJECTS) $(patsubst %.cc,objects/%.o,$(STERPSRCS)) ../lib/liblinuxcncini.so ../lib/librs274.so
	cp $(EXTERN)antlr4/lib/libantlr4-runtime.so.4.13.2 ../lib/libantlr4-runtime.so.4.13.2
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(ECHO) Linking $(notdir $@)
	$(Q)mkdir -p ../lib/linuxcnc
	$(Q)rm -f $@
	$(Q)$(CXX) -Wl,--whole-archive $(LDFLAGS) -Wl,--no-whole-archive \
  -Wl,-soname,$(notdir $@) -shared -o $@ $^ $(LIBDL)

linuxcnc: $(call TOOBJSDEPS, $(STERPSRCS))

test:
	echo "Working on $(TEST_TYPE) tests."
	$(MAKE) --no-print-directory $(TEST_TYPE)

unit: $(OBJECTS) $(ANTLR4_OBJECTS) $(UNIT_TEST_FILES)
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(CXX) $(UNIT_TEST_FILES) \
		$(OBJECTS) $(ANTLR4_OBJECTS) -o $(THISDIR)build/unit $(CXXFLAGS) $(LDFLAGS) $(TEST_INCLUDE)
	./$(THISDIR)build/unit

regression: $(OBJECTS) $(ANTLR4_OBJECTS)
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(CXX) tests/regression.cpp $(TEST_INCLUDE) \
		$(OBJECTS) $(ANTLR4_OBJECTS) -o $(THISDIR)build/regression $(CXXFLAGS) $(LDFLAGS)
	./$(THISDIR)build/regression -s

antlr:
	mkdir -p $(THISDIR)build $(THISDIR)out
	cd $(EXTERN)antlr4 && java -jar $(EXTERN)antlr4/antlr-4.13.2-complete.jar -Dlanguage=Cpp \
		-visitor -o $(EXTERN)antlr4/gen $(THISDIR)antlr4/lexer_antlr4.g4 $(THISDIR)antlr4/parser_antlr4.g4

dev: $(OBJECTS) $(ANTLR4_OBJECTS)
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(CXX) src/main.cpp $(OBJECTS) $(ANTLR4_OBJECTS) -o $(THISDIR)build/$(TITLE) \
		$(CXXFLAGS) $(LDFLAGS)

DIR = /usr/local/bin
install: $(OBJECTS) $(ANTLR4_OBJECTS)
	sudo $(CXX) src/main.cpp $(OBJECTS) $(ANTLR4_OBJECTS) -o $(DIR)/$(TITLE) \
		$(CXXFLAGS) $(LDFLAGS)

$(THISDIR)build/lexer_antlr4.o: $(EXTERN)antlr4/gen/lexer_antlr4.cpp
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(THISDIR)build/parser_antlr4.o: $(EXTERN)antlr4/gen/parser_antlr4.cpp
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(THISDIR)build/parser_antlr4BaseVisitor.o: $(EXTERN)antlr4/gen/parser_antlr4BaseVisitor.cpp
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXTERN)antlr4/gen/%.cpp: $(THISDIR)antlr4/lexer_antlr4.g4 $(THISDIR)antlr4/parser_antlr4.g4
	mkdir -p $(THISDIR)build $(THISDIR)out
	cd $(EXTERN)antlr4 && java -jar $(EXTERN)antlr4/antlr-4.13.2-complete.jar -Dlanguage=Cpp \
		-visitor -o $(EXTERN)antlr4/gen $(THISDIR)antlr4/lexer_antlr4.g4 $(THISDIR)antlr4/parser_antlr4.g4

$(THISDIR)build/%.o: $(THISDIR)src/%.cpp
	mkdir -p $(THISDIR)build $(THISDIR)out
	$(CXX) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -rf ${OBJECTS} $(ANTLR4_OBJECTS) $(THISDIR)build/unit.o $(THISDIR)build/unit \
		$(THISDIR)build/regression $(THISDIR)build/regression.o $(EXTERN)antlr4/gen/* $(THISDIR)build/$(TITLE)

name ?= newfile
new:
	printf "#ifndef smv_gpp_$(name)_hpp\n" > include/$(name).hpp
	printf "#define smv_gpp_$(name)_hpp\n\n\n#endif\n" >> include/$(name).hpp
	printf "#include \"$(name).hpp\"" > src/$(name).cpp

