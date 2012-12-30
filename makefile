# linux #
ifeq ($(UNAME),Linux)
	CMAKE_GENERATOR:="Unix Makefiles"
endif

# windows / mingw #
ifeq ($(UNAME:MINGW%=MINGW),MINGW)
	CMAKE_GENERATOR:="MSYS Makefiles"
endif

all: build/Makefile
	@cd build; $(MAKE) --no-print-directory

install: build/Makefile
	@cd build; $(MAKE) install --no-print-directory >/dev/null

build/Makefile:
	mkdir -p build
	cd build; cmake -G $(CMAKE_GENERATOR) .. -DCMAKE_INSTALL_PREFIX=$(CURDIR)

clean:
	rm -rf build
	rm -rf include
	rm -rf lib

# ZETHES_INCLUDE=$(ZETHES_PATH)/include
# ZETHES_LIB=$(ZETHES_PATH)/lib

# CPP_FILES:=$(wildcard src/*.cpp) $(wildcard src/*/*.cpp) $(wildcard src/*/*/*.cpp)
# H_FILES:=$(wildcard *.h) $(wildcard */*.h) $(wildcard */*/*.h)
# OBJ_FILES:=$(CPP_FILES:src/%.cpp=obj/%.o)
# DEP_FILES:=$(CPP_FILES:.cpp=.d) $(MM_FILES:.mm=.dd)
# DEP_FILES:=$(addprefix dep/,$(DEP_FILES:src/%=%))
# INCLUDE_FILES:=$(H_FILES:src/%=include/Jatta/%.force)
# COMPILE_SETTINGS=-DJATTA_INCLUDES -DJATTA_DEBUG

# UNAME:=$(shell uname -s)

# # linux #
# ifeq ($(UNAME),Linux)
# 	COMPILE_SETTINGS:=$(COMPILE_SETTINGS) -DLINUX
# endif

# # mac os x #
# ifeq ($(UNAME),Darwin)
# 	COMPILE_SETTINGS:=$(COMPILE_SETTINGS) -DMACOS
# endif

# # windows / mingw #
# ifeq ($(UNAME:MINGW%=MINGW),MINGW)
# 	COMPILE_SETTINGS:=$(COMPILE_SETTINGS) -DWINDOWS
# endif

# lib/libjatta.a: $(OBJ_FILES) $(INCLUDE_FILES)
# 	@mkdir -p lib
# 	ar rcs lib/libjatta.a $(OBJ_FILES)

# -include $(DEP_FILES)

# include/Jatta/%.force:
# 	@mkdir -p $(dir $(@:%.force=%))
# 	@cp src/$* $(@:%.force=%)

# obj/%.o: src/%.cpp
# 	@mkdir -p $(dir $@)
# 	@mkdir -p dep/$(dir $*)
# 	g++ -g -c src/$*.cpp -o $@ -std=gnu++11 -I$(ZETHES_INCLUDE) -DGLEW_NO_GLU -DGLEW_STATIC -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x501 $(COMPILE_SETTINGS)
# 	@g++ -MM src/$*.cpp  -std=gnu++11 -I$(ZETHES_INCLUDE) -DGLEW_NO_GLU -DGLEW_STATIC -DWIN32_LEAN_AND_MEAN -D_WIN32_WINNT=0x501 $(COMPILE_SETTINGS) > dep/$*.d.tmp
# 	@sed -e 's|.*:|obj/$*.o:|' < dep/$*.d.tmp > dep/$*.d
# 	@sed -e 's/.*://' -e 's/\\$$//' < dep/$*.d.tmp | \
# 	  sed -e 's/^ *//' -e 's/$$/:/' >> dep/$*.d
# 	@rm -f dep/$*.d.tmp

# clean:
# 	rm -rf include/Jatta
# 	#rm -rf lib
# 	rm -rf obj
# 	rm -rf dep
