BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
ARR = $(SRC)/AQueue
LL = $(SRC)/LinkedListQueue
STL = $(SRC)/ListQueue
TTEST = $(SRC)/TimingTests

CPP = g++
CPPFLAGS = -Wall -Wextra

all: $(BUILD)/Atime $(BUILD)/LLtime $(BUILD)/STLtime $(TEST)/Atest $(TEST)/LLtest $(TEST)/STLtest

$(BUILD)/Atime: $(TTEST)/queue_tester.cpp $(ARR)/Queue.o
	cd $(SRC); $(MAKE)

$(ARR)/Queue.o: $(ARR)/Queue.cpp $(ARR)/Queue.h
	cd $(ARR); $(MAKE)

$(BUILD)/LLtime: $(TTEST)/queue_tester.cpp $(LL)/Queue.o
	cd $(SRC); $(MAKE)

$(LL)/Queue.o: $(LL)/Queue.cpp $(LL)/Queue.h $(LL)/Node.o
	cd $(LL); $(MAKE)

$(LL)/Node.o: $(LL)/Node.cpp $(LL)/Node.h
	cd $(LL); $(MAKE)

$(BUILD)/STLtime: $(TTEST)/queue_tester.cpp $(STL)/Queue.o
	cd $(SRC); $(MAKE)

$(STL)/Queue.o: $(STL)/Queue.cpp $(STL)/Queue.h
	cd $(STL); $(MAKE)

$(TEST)/Atest: $(TEST)/Queue.cpp $(ARR)/Queue.o
	cd $(TEST); $(MAKE)

$(TEST)/LLtest: $(TEST)/Queue.cpp $(LL)/Queue.o
	cd $(TEST); $(MAKE)

$(TEST)/STLtest: $(TEST)/Queue.cpp $(STL)/Queue.o
	cd $(TEST); $(MAKE)

clean:
	cd $(SRC); $(MAKE) clean
	cd $(TEST); $(MAKE) clean

