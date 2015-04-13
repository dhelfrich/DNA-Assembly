#include "dna.assemble.h"


//A, G, C, T are numbers between 1 and 10, summing to 10, representing
//the proportion of bases in the random strand
char randomBase(int A, int G, int C, int T)
{
  if(A + G + C + T != 10)
    std::cout << "error: ATCG not in right form" << std::endl;
  int ran = std::rand() % 10;
  if(ran < A)
    return 'A';
  else if(ran < G + A)
    return 'G';
  else if(ran < C + G + A)
    return 'C';
  else if(ran < 10)
    return 'T';
  else{
    std::cout << "error: couldn't pick base" << std::endl;
    return 'E';
  }
}

void createSeq(std::vector<char> &seq , int n)
{
  seq.clear();
  for (int i = 0; i < n; ++i) //Create random sequence
    seq.push_back(randomBase(1, 4, 2, 3));
}

void readSeq(std::vector<char> &seq, std::ifstream& input)
{
  seq.clear();
  char base;
  while(input >> base) {
    if(base != ' ')
      seq.push_back(std::toupper(base));
  }
  return;
}

//Brute force algorithm to find k,
//The smallest number s.t. each subsequence of length
//k occurs at most once

int findk(const std::vector<char> & seq, bool verbose)
{
  int n = seq.size();
  for (int k = 1; k < n; ++k) //for all k's less than the size
    if(testk(seq, k, verbose))
      return k;
  return n;
}
 
inline bool testk(const std::vector<char> & seq, int k, bool verbose)
{
  std::vector<char>::const_iterator first =seq.begin();
  int n = seq.size();
  for (int i = 0; i < n - k + 1; ++i){ //for each starting position
    std::vector<char> kmer(first + i, first + i + k);
    for (int j = i + 1; j < n - k + 1; ++j){//check k-mer against remaining sequence
      std::vector<char> section(first + j, first + j + k);
      if(kmer == section){
        if(verbose){
          std::cout << "section at pos: " << i << " = section at pos: " << j << std::endl;
          std::cout << "section = ";
          std::copy(kmer.begin(), kmer.end(), std::ostream_iterator<char>(std::cout, " "));
          std::cout << std::endl;
        }
        return false; //repeated
      }
    }
  }
  return true; //unique
}


