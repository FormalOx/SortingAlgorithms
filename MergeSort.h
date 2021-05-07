#ifndef MSMPI
#define MSMPI
#include <vector>

std::vector<int> mergeSort( std::vector<int> a1 ) {
  
  if( a1.size() < 3 ) {
    if( a1.size() == 2 && a1[ 0 ] > a1[ 1 ] ) {
      int d = a1[ 0 ];
      a1[ 0 ] = a1[ 1 ];
      a1[ 1 ] = d;
      return a1;
    }
    return a1;
  }
  int split = a1.size() / 2;
  
  std::vector<int> hi, lo;
  
  hi.assign( a1.begin(), a1.begin() + split );
  
  lo.assign( a1.begin() + split, a1.end() );
  
  hi = mergeSort( hi );
  lo = mergeSort( lo );
  
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
