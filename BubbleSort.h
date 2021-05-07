/*
  ID     : 00?
  NAME   : Buble Sort
  DATE   : 7 mar
  TYPE   : U
*/
#ifndef BSMPI
#define BSMPI
#include <vector>

std::vector<int> bubbleSort( std::vector<int> alpha ) {
  int   delta;
  bool  sorting = true;
  while( sorting ) {
    sorting = false;
    for ( unsigned int i = 0; i < alpha.size() - 1; i++ ) {
      if( alpha[ i ] > alpha[ i + 1 ] ) {
        delta = alpha[ i ];
        alpha[ i ] = alpha[ i + 1 ];
        alpha[ i + 1 ] = delta;
        sorting = true;
      }
    }
  }
  return alpha;
}

#endif
