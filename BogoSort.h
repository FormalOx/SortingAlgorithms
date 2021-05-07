/*
  ID     : 00?
  NAME   : Quick Sort
  DATE   : 7 mar
  TYPE   : U
*/
#ifndef BGSMPI
#define BGSMPI
#include <vector>
#include <stdlib.h>

std::vector<int> bogoSort ( std::vector<int> a1 ) {
  bool isSorted = false;
  int d1, d2;
  if( a1.size() == 0 ) { return a1; }
  const int c1 = a1.size();
  while( true ) {
    isSorted = true;
    for( std::vector<int>::const_iterator i = a1.begin(); i != a1.end() - 1; i++ ) {
      if( *i > *( i + 1 ) ) { isSorted = false; break; }
    }
    if( isSorted ) { return a1; }
    for( int i = 0; i < c1; i++ ) {
      d1 = a1[ i ];
      d2 = rand() % c1;
      a1[ i ] = a1[ d2 ];
      a1[ d2 ] = d1;
    }
  }
  return a1;
}

#endif
