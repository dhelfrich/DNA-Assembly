#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <ctype.h>

char randomBase(int A, int G, int C, int T);
void createSeq(std::vector<char> &seq , int n);
int findk(const std::vector<char> & seq, bool verbose);
bool testk(const std::vector<char> & seq, int k, int& startPos, bool verbose);
void readSeq(std::vector<char> &seq, std::ifstream& input);


