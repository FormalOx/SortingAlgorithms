#ifndef TSMPI 
#define TSMPI

#include <vector>

#include "InsertionSort.h"

#define CUTOFF 32

std::vector<int> timSort( std::vector<int> a1 ) {
  if( a1.size() < CUTOFF ) {
    a1 = insertionSort( a1 );
    return a1;
  }
  
  int split = a1.size() / 2;
  
  std::vector<int> hi, lo;
  
  hi.assign( a1.begin(), a1.begin() + split );
  
  lo.assign( a1.begin() + split, a1.end() );
  
  hi = timSort( hi );
  lo = timSort( lo );
  
  a1.clear();
  
  unsigned int i = 0, k = 0;
  while ( i < hi.size() && k < lo.size() ) {
    if( hi[ i ] < lo[ k ] ) {
      a1.push_back( hi[ i++ ] );
    } else {
      a1.push_back( lo[ k++ ] );
    }
  }
  while( i < hi.size() ) {
    a1.push_back( hi[ i++ ] );
  }
  while( k < lo.size() ) {
    a1.push_back( lo[ k++ ] );
  }
  
  return a1;
}

#endif
