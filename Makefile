CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -O2 -fopenmp
LDFLAGS=-g 

SRCS= main.cpp

main: main.cpp main.h
	$(OBJS) $(CXX) $(CPPFLAGS) -o main $(OBJS) $(SRCS)

clean:
	rm -f $(FILES) *.o *~

