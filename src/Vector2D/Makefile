CPP = g++
CPPFLAGS = -Wall -Wextra

test: test.cpp TwoDArray.o
	$(CPP) $(CPPFLAGS) -o test test.cpp TwoDArray.o

TwoDArray.o: TwoDArray.h TwoDArray.cpp
	$(CPP) $(CPPFLAGS) -c TwoDArray.cpp

clean:
	rm -f *.o
	rm -f *~


