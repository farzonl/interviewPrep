
#_____________STATIC STUFF__________________________________________
OPTIONS := -std=c++11 -Wall
INCPATH := -I test/include -I datastructures/include -I include
FILES := test/test.cpp src/*.cpp
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

$(EXE) : $(FILES)
	$(CC) $^ -o $(EXE) $(CFLAGS)

build-debug : CFLAGS += -g -DDEBUG
build-debug : $(EXE)

clean :
	rm -rf *.o* $(EXE)*

rebuild : clean build-release