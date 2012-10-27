BUILD = ./build
TEST = ./test
LIB = ./lib
SRC = ./src
SPARSE = $(SRC)/Sparse2D2
VEC = $(SRC)/Vector2D
VECH = $(SRC)/Vector2Dheap
ARR = $(SRC)/Array2D

PRE = TwoDArray
LPRE = LinkedList
NPRE = Node

GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a

GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra

all: $(TEST)/Vtest $(TEST)/VHtest $(TEST)/Atest $(TEST)/Stest

$(TEST)/Stest: $(TEST)/$(PRE)Test.cpp $(SPARSE)/$(PRE).o $(SPARSE)/$(LPRE).o $(SPARSE)/$(NPRE).o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o Stest $(TEST)/$(PRE)Test.cpp $(SPARSE)/$(PRE).o $(SPARSE)/$(LPRE).o $(SPARSE)/$(NPRE).o $(GTEST_MAINA)

$(SPARSE)/$(PRE).o: $(SPARSE)/$(PRE).cpp $(SPARSE)/$(PRE).h $(SPARSE)/$(LPRE).o $(SPARSE)/$(NPRE).o
	cd $(SPARSE); $(MAKE)

$(SPARSE)/$(LPRE).o: $(SPARSE)/$(LPRE).cpp $(SPARSE)/$(LPRE).h $(SPARSE)/$(NPRE).o
	cd $(SPARSE); $(MAKE)

$(SPARSE)/Node.o: $(SPARSE)/Node.cpp $(SPARSE)/Node.h
	cd $(SPARSE); $(MAKE)

$(TEST)/Vtest: $(TEST)/$(PRE)Test.cpp $(VEC)/$(PRE).o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o Vtest $(TEST)/$(PRE)Test.cpp $(VEC)/$(PRE).o $(GTEST_MAINA)

$(VEC)/$(PRE).o: $(VEC)/$(PRE).cpp $(VEC)/$(PRE).h
	cd $(VEC); $(MAKE)

$(TEST)/VHtest: $(TEST)/$(PRE)Test.cpp $(VECH)/$(PRE).o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o VHtest $(TEST)/$(PRE)Test.cpp $(VECH)/$(PRE).o $(GTEST_MAINA)

$(VECH)/$(PRE).o: $(VECH)/$(PRE).cpp $(VECH)/$(PRE).h
	cd $(VECH); $(MAKE)

$(TEST)/Atest: $(TEST)/$(PRE)Test.cpp $(ARR)/$(PRE).o $(GTEST_Maina)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o Atest $(TEST)/$(PRE)Test.cpp $(ARR)/$(PRE).o $(GTEST_MAINA)

$(ARR)/$(PRE).o: $(ARR)/$(PRE).cpp $(ARR)/$(PRE).h
	cd $(ARR); $(MAKE) 

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

clean:
	rm -f $(TEST)/*test
	rm -f $(GTEST_MAINA)
	cd $(SPARSE); $(MAKE) clean
	cd $(VEC); $(MAKE) clean
	cd $(VECH); $(MAKE) clean
	cd $(ARR); $(MAKE) clean
	cd $(GTEST)/make; $(MAKE) clean
	cd $(TEST)

