CPP = g++
CPPFLAGS = -Wall -Wextra 

#all: test nodetest

#test: test.cpp TwoDArray.o LinkedList.o Node.o
#	$(CPP) $(CPPFLAGS) -o test test.cpp TwoDArray.o LinkedList.o Node.o

all: TwoDArray.o LinkedList.o Node.o

TwoDArray.o: TwoDArray.h TwoDArray.cpp LinkedList.o Node.o
	$(CPP) $(CPPFLAGS) -c TwoDArray.cpp

LinkedList.o: LinkedList.h LinkedList.cpp Node.o
	$(CPP) $(CPPFLAGS) -c LinkedList.cpp

#nodetest: nodetest.cpp Node.o
#	$(CPP) $(CPPFLAGS) -o nodetest nodetest.cpp Node.o

Node.o: Node.h Node.cpp
	$(CPP) $(CPPFLAGS) -c Node.cpp

clean:
	rm -f *.o
	rm -f *~
	rm -f test
	rm -f nodetest

