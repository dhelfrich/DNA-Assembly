#include <assert.h>

#include "test.h"

// Returns nonzero exit code upon failure.

int main(int argc, char *argv[])
{
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  std::srand((time_t) ts.tv_nsec);
  
  int n = 10; //length of sequence
  if (argc > 1)
    n = atoi(argv[1]);


  std::vector<char> seq = {'A','T','G','A'};
  if (findk(seq, false) != 2) return 1;
  seq = {'A', 'A', 'A'};
  if (findk(seq, false) != 3) return 2;
  seq = {'A', 'T', 'A', 'T'};
  if (findk(seq, false) != 3) return 3;
  seq = {'A', 'T', 'A', 'T', 'A'};
  if (findk(seq, false) != 4) return 4;
  seq = {'A', 'G', 'A', 'T', 'A'};
  if (findk(seq, false) != 2) return 5;

  // Just a smoketest.
  createSeq(seq, n);

//  std::vector<char> seq = {'A','T','G','A'};
//  createSeq(seq, n);
//  std::cout << "seq = "; 
//  std::copy(seq.begin(), seq.end(), std::ostream_iterator<char>(std::cout, " "));
//  std::cout << std::endl;
//  std::cout << "k = " << findk(seq, 1) << std::endl;
//  int k = 1;
//  std::cout << "k = " << k << " Unique?: " << testk(seq, k, true) << std::endl;
//  k = 2;
//  std::cout << "k = " << k << " Unique?: " << testk(seq, k, true) << std::endl;
//  k = 3;
//  std::cout << "k = " << k << " Unique?: " << testk(seq, k, true) << std::endl;
//  k = 4;
//  std::cout << "k = " << k << " Unique?: " << testk(seq, k, true) << std::endl;
  
//  int countA = 0;
//  for (std::vector<char>::const_iterator i = seq.begin(); i != seq.end(); ++i) {
//    if (*i == 'C')
//      countA++;
//  }
//  std::cout << "G appears " << countA << " times" << std::endl;
  

//  std::vector<char> seq;
  createSeq(seq, n);                                                              
  std::cout << "seq = ";                                                          
  std::copy(seq.begin(), seq.end(), std::ostream_iterator<char>(std::cout, " ")); 
  std::cout << std::endl;                                                         
  std::cout << "k = " << findk(seq, 1) << std::endl;                              

  //read the file

  return 0;
}
