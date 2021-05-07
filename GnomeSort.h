#ifndef GSMPI
#define GSMPI

#include <vector>

std::vector<int> gnomeSort( std::vector<int> a1 ) {
  int n = a1.size();
  int deltaS;
  for( int i = 1; i < n; ) {
    if( i == 0 ) i++;
    if( a1[ i ] < a1[ i - 1 ] ) {
      deltaS = a1[ i ];
      a1[ i ] = a1[ i - 1 ];
      a1[ i - 1 ] = deltaS;
      i--;
    } else {
      i++;
    }
  }
  return a1;
}

#endif
