#include "main.h"


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

//Brute force algorithm to find k,
//The smallest number s.t. each subsequence of length
//k occurs at most once

int findk(const std::vector<char> & seq)
{
  int n = seq.size();
  std::vector<char>::const_iterator first =seq.begin();
  for (int k = 1; k < n; ++k){ //for all k's less than the size
NEW_K: //Break out of loops
    for (int i = 0; i < n - k; ++i){ //for each starting position
      std::vector<char> kmer(first + i, first + i + k);
      for (int j = i + 1; j < n; ++j){//check k-mer against remaining sequence
        std::vector<char> section(first + j, first + j + k);
        if(kmer == section){
          //std::cout << "section at pos: " << i << " = section at pos: " << j << std::endl;
          //std::cout << "section = ";
          //std::copy(kmer.begin(), kmer.end(), std::ostream_iterator<char>(std::cout, " "));
          //std::cout << std::endl;
          k++;
          goto NEW_K;
        }
      }
    }
    return k; //If here, then for each starting position, the kmer doesn't match any sequence
  }
}



int main(int argc, char *argv[])
{
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  std::srand((time_t) ts.tv_nsec);
  
  int n = 10;
  if (argc > 0)
    n = atoi(argv[1]);

  std::vector<char> seq;                                              
  createSeq(seq, n);

//  std::cout << "seq = "; 
//  std::copy(seq.begin(), seq.end(), std::ostream_iterator<char>(std::cout, " "));
//  std::cout << std::endl;
  
//  int countA = 0;
//  for (std::vector<char>::const_iterator i = seq.begin(); i != seq.end(); ++i) {
//    if (*i == 'C')
//      countA++;
//  }
//  std::cout << "G appears " << countA << " times" << std::endl;
  

//  for (int i = 0; i < 10000; ++i){
//    createSeq(seq, n);
//    std::cout << findk(seq) << std::endl;
//  }
  std::vector<char> seq32;                                              
  std::vector<char> seq64;                                              
  std::vector<char> seq128;                                              
  std::vector<char> seq256;                                              
  std::vector<char> seq512;                                              
  std::cout << "k32,k64,k128,k256,k512" << std::endl;
  for (int i = 0; i < n; ++i){
    createSeq(seq32, 32);
    createSeq(seq64, 64);
    createSeq(seq128, 128);
    createSeq(seq256, 256);
    createSeq(seq512, 512);

    std::cout <<
      findk(seq32) << "," << 
      findk(seq64) <<  "," << 
      findk(seq128) << "," << 
      findk(seq256) << "," << 
      findk(seq512) << std::endl;
  }
  return 0;
}
