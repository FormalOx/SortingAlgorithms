/*
  ID     : 00?
  NAME   : Heap Sort
  DATE   : 7 mar
  TYPE   : U
*/
#ifndef HSMPI
#define HSMPI
#include <vector>

std::vector<int> validateHeap( std::vector<int> alpha, int depth, int i ) {
  int d1 = i * 2 + 1;
  int d2 = i * 2 + 2;
  int d3 = i;
  if( d1 < depth && alpha[ d1 ] > alpha[ d3 ] ) {
    d3 = d1;
  }
  if( d2 < depth && alpha[ d2 ] > alpha[ d3 ] ) {
    d3 = d2;
  }
  if( d3 != i ) {
    d1 = alpha[ d3 ];
    alpha[ d3 ] = alpha[ i ];
    alpha[ i ] = d1;
    return validateHeap( alpha, depth, d3 );
  }
  return alpha;
}

std::vector<int> heapSort( std::vector<int> alpha ) {
  for( int i = alpha.size() / 2 - 1; i >= 0; i-- ) {
    alpha = validateHeap ( alpha, alpha.size(), i );
  }
  int d1;
  for( int i = alpha.size() - 1; i > 0; i-- ) {
    d1 = alpha[ i ];
    alpha[ i ] = alpha[ 0 ];
    alpha[ 0 ] = d1;
    alpha = validateHeap( alpha, i, 0 );
  }
  return alpha;
}

#endif
