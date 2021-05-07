#ifndef ISMPI
#define ISMPI

#include <vector>

std::vector<int> insertionSort( std::vector<int> a1 ) {
  int d1, d2;
  for( unsigned int i = 0; i < a1.size(); i++ ) {
    d2 = i;
    while( d2 > 0 && a1[ d2 ] < a1[ d2 - 1 ] ) {
      d1 = a1[ d2 ];
      a1[ d2 ] = a1[ d2 - 1 ];
      a1[ d2 - 1 ] = d1;
      d2--;
    }
  } 
  return a1;
}

#endif
