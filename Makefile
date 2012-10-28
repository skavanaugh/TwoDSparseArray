BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
#ARR = $(SRC)/AQueue
#LL = $(SRC)/LinkedListQueue
#STL = $(SRC)/ListQueue
#TTEST = $(SRC)/TimingTests

CPP = g++
CPPFLAGS = -Wall -Wextra

all:
	cd $(TEST); $(MAKE)

clean:
	cd $(TEST); $(MAKE) clean

