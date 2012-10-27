BUILD = ../build
TEST = ../test
LIB = ../lib
SRC = ../src
LL = $(SRC)/LinkedListQueue
STL = $(SRC)/ListQueue
ARR = $(SRC)/AQueue

GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a

GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra

all: LLtest STLtest Atest

LLtest: Queue.cpp $(LL)/Queue.o $(LL)/Node.o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o LLtest Queue.cpp $(LL)/Queue.o $(LL)/Node.o $(GTEST_MAINA)

$(LL)/Queue.o: $(LL)/Queue.cpp $(LL)/Queue.h $(LL)/Node.o
	cd $(LL); $(MAKE)

$(LL)/Node.o: $(LL)/Node.cpp $(LL)/Node.h
	cd $(LL); $(MAKE)

STLtest: Queue.cpp $(STL)/Queue.o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o STLtest Queue.cpp $(STL)/Queue.o $(GTEST_MAINA)

$(STL)/Queue.o: $(STL)/Queue.cpp $(STL)/Queue.h
	cd $(STL); $(MAKE)

Atest: Queue.cpp $(ARR)/Queue.o $(GTEST_Maina)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o Atest Queue.cpp $(ARR)/Queue.o $(GTEST_MAINA)

$(ARR)/Queue.o: $(ARR)/Queue.cpp $(ARR)/Queue.h
	cd $(ARR); $(MAKE) 

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

clean:
	rm -f LLtest STLtest Atest
	rm -f $(GTEST_MAINA)
	cd $(LL); $(MAKE) clean
	cd $(STL); $(MAKE) clean
	cd $(ARR); $(MAKE) clean
	cd $(GTEST)/make; $(MAKE) clean
	cd $(TEST)

