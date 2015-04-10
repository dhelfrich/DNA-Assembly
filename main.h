
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iterator>

const char DNA[4] = {'A','G','C','T'};
char randomBase(int A, int G, int C, int T);
void createSeq(std::vector<char> &seq , int n);
int findk(const std::vector<char> & seq, int n);
int main(int argc, char *argv[]);
