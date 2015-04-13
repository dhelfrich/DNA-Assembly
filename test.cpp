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


  std::vector<char> seq = {'C', 'C', 'A', 'T'};  // RC: ATGG
  if (findk(seq, false) != 3) return 1;

  seq = {'A', 'A', 'A'};
  if (findk(seq, false) != 3) return 2;

  // Test circularity.
  seq = {'A', 'T', 'A', 'T'};  // RC: ATAT
  if (findk(seq, false) != 4) { std::cout << findk(seq, false) << std::endl; return 3; }

  seq = {'A', 'T', 'A', 'T', 'A'};
  if (findk(seq, false) != 5) { std::cout << findk(seq, false) << std::endl; return 4; }

  // Test reverse complement.
  seq = {'T','A'};  // RC: TA
  if (!compare(seq, 0, 0, 2, true)) { return 12; }
  if (compare(seq, 0, 1, 2, true)) { return 13; }
  seq = {'T','A', 'C'};  // RC: GTA
  if (!compare(seq, 0, 1, 2, true)) { return 14; }
  if (findk(seq, false) != 3) { std::cout << findk(seq, false) << std::endl;  return 11; }

  seq = {'A', 'G', 'A', 'T', 'A'};  // RC: TATCT
  if (findk(seq, false) != 3) { std::cout << findk(seq, false) << std::endl; return 5; }
  seq = {'A','T','G','A'};  // RC: TCAT
  if (findk(seq, false) != 3) return 6;
  seq = {'A','T','G','C'};  // RC: GCAT
  if (findk(seq, false) != 4) return 7;

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
//  //read the file

  return 0;
}
