
#_____________STATIC STUFF__________________________________________
OPTIONS := -std=c++11 -Wall -Wextra  -Wstrict-aliasing -pedantic -Werror -Wunreachable-code -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -Wno-variadic-macros -Wno-parentheses -fdiagnostics-show-option 
INCPATH := -I test/include -I datastructures/include -I include
FILES := test/test.o $(shell echo src/*.cpp  | sed -e 's/cpp/o/g')
UNAME := $(shell uname)
EXE   := $(UNAME)_test
#_____________STATIC STUFF__________________________________________
ifeq ($(UNAME),Darwin)
CC := clang++
else
CC := g++
endif
CFLAGS := $(INCPATH) $(LIBPATH) $(OPTIONS)

run : build-release
	./$(EXE)

run-debug : build-debug
	./$(EXE)

run-valgrind : build-debug
	valgrind --leak-check=yes --show-reachable=yes --tool=memcheck ./EXE

build-release : CFLAGS += -O3
build-release : $(EXE)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXE) : $(FILES)
	$(CC) $^ -o $(EXE) $(CFLAGS)

build-debug : CFLAGS += -g -DDEBUG
build-debug : $(EXE)

clean :
	rm -rf *.o* src/*.o* $(EXE)*

rebuild : clean build-release