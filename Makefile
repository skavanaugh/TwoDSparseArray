BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src

CPP = g++
CPPFLAGS = -Wall -Wextra

all:
	cd $(TEST); $(MAKE)

clean:
	cd $(TEST); $(MAKE) clean

