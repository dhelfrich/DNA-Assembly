CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -O2
LDFLAGS=-g 

SRCS= main.cpp

main: main.cpp main.h
	$(OBJS) $(CXX) $(LDFLAGS) -o main $(OBJS) $(SRCS)

clean:
	rm -f $(FILES) *.o *~

