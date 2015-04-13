#include "main.h"




int main(int argc, char *argv[])
{
  struct timespec ts;
  clock_gettime(CLOCK_MONOTONIC, &ts);
  std::srand((time_t) ts.tv_nsec);
  
  int n = 10; //number of trials
  if (argc > 1)
    n = atoi(argv[1]);

std::vector<char> seq;
if(n == 0)
{
  std::ifstream inputfile(argv[2]);
  readSeq(seq, inputfile);
  //std::cout << "seq = ";                                                          
  //std::copy(seq.begin(), seq.end(), std::ostream_iterator<char>(std::cout, " ")); 
  //std::cout << std::endl;                                                         
  std::cout << "k = " << findk(seq, 1) << std::endl;                              
}
else
{
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
      findk(seq32,0) << "," << 
      findk(seq64,0) <<  "," << 
      findk(seq128,0) << "," << 
      findk(seq256,0) << "," << 
      findk(seq512,0) << std::endl;
  }
}
  return 0;
}
