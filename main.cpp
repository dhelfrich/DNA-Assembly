#include "main.h"


void createSeq(std::vector<char> &seq , int n)
{
  for (int i = 0; i < n; ++i) //Create random sequence
    seq.push_back(DNA[std::rand() % 4]);
}

//Brute force algorithm to find k,
//The smallest number s.t. each subsequence of length
//k occurs at most once

int findk(const std::vector<char> & seq)
{
  int n = seq.size();
  for (int i = 1; i < n; ++i){ //for all k's less than the size

  }
}



int main(int argc, char *argv[])
{
  std::srand(std::time(0));
  std::vector<char> seq;
  createSeq(seq, 10000);
  for (std::vector<char>::iterator i = seq.begin();i  < seq.end(); i++)
    std::cout << *i;
  return 0;
}
