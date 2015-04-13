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

int findk(const std::vector<char>& seq, bool verbose) {
  int startPos = 0;
  int n = seq.size();
  bool reverse = false;
  int k_unique = n;
  for (int k = 1; k < n; ++k) {  //for all k's less than the size
    if (testk(seq, k, startPos, reverse, verbose)) {
      k_unique = k;
      break;
    }
  }

  reverse = true;
  startPos = 0;
  for (int k = k_unique; k < n; ++k) {  //for all k's less than the size
    if (testk(seq, k, startPos, reverse, verbose)) {
      return k;
    }
  }
  return n;
}

// Compare kmers, including circularity and reverse complements.
// Params:
//   seq the sequence to compare
//   seq_size the number of characters in the sequence.
//   pos1 the position of the first base in the first kmer
//   pos2 the position of the first base in the second kmer
//   k the size of the kmers
//   rev_comp if true, compare reverse complements.
bool compare(const std::vector<char>& seq,
        int pos1, int pos2, int k, bool rev_comp) {
  int seq_size = seq.size();
  if (rev_comp) {
    for (int i = 0; i < k; ++i) {
      char base1 = seq[(pos1 + i) % seq_size];
      char base2 = seq[(3*seq_size - 1 - pos2 - i) % (seq_size)];
      switch (base1) {
        case 'A':
          if (base2 != 'T') return false;
          break;
        case 'T':
          if (base2 != 'A') return false;
          break;
        case 'G':
          if (base2 != 'C') return false;
          break;
        case 'C':
          if (base2 != 'G') return false;
          break;
        default:
          std::cerr << "Invalid base type detected." << std::endl;
          throw 100;
      }
    }
    return true;
  } else {
    for (int i = 0; i < k; ++i) {
      char base1 = seq[(pos1 + i) % seq_size];
      char base2 = seq[(pos2 + i) % seq_size];
      if (seq[(pos1 + i) % seq_size] != seq[(pos2 + i) % seq_size]) return false;
    }
    return true;
  }
}

bool testk(const std::vector<char>& seq, int k, int& startPos, bool reverse, bool verbose) {
  int n = seq.size();
  for (; startPos < n; ++startPos){  //for each starting position
    if (verbose && startPos % 10000 == 0) std::cout << "start pos: " << startPos << std::endl;
    for (int j = startPos + 1; j <= startPos + 1 + k; ++j){  //check k-mer against remaining sequence
      if (compare(seq, startPos, j, k, reverse)){
        if (verbose){
          std::cout << "section at pos: " << startPos << " = section at pos: " << j << std::endl;
        }
        return false;  //repeated
      }
    }
  }
  return true;  //unique
}
