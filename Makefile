CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS= -g -O2 -std=c++11
LDFLAGS= -c -g -O2 -std=c++11
OBJS = dna.assemble.o

SRCS= main.cpp




main: $(OBJS) main.cpp main.h
	$(CXX) $(OBJS) $(CPPFLAGS) -o main main.cpp

test: $(OBJS) test.cpp test.h
	$(CXX) $(OBJS) $(CPPFLAGS) -o test test.cpp

dna.assemble.o : dna.assemble.h dna.assemble.cpp
	$(CXX) $(LDFLAGS) -o dna.assemble.o dna.assemble.cpp

clean:
	rm -f $(FILES) *.o *~

