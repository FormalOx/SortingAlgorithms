/*
  ID     : 00?
  NAME   : Selection Sort for MPI
  DATE   : 7 mar
  TYPE   : U
*/
#ifndef SSMPI
#define SSMPI
#include <vector>

std::vector<int> selectionSort( std::vector<int> alpha ) {
  int split = 0, d, start;
  const int s = alpha.size();
  for( int i = 0; i < s; i++ ) {
    start = 0; d = split;
    for( int k = split; k < s; k++ ) {
      if( alpha[ k ] < alpha[ d ] || start == 0 ) {
        d = k;
        start = 1;
      }
    }
    start = alpha[ d ];
    alpha[ d ] = alpha[ split ];
    alpha[ split ] = start;
    split++; 
  }
  return alpha;
}

#endif
