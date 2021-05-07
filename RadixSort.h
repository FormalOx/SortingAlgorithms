#ifndef RDMPI
#define RDMPI

#include <vector>

std::vector<int> radixSort ( std::vector<int> alpha, int base, int depth ) {
  if( depth == 0 ) {
    return alpha;
  } 

  std::vector<std::vector<int>> delta ( base );
 
  for( std::vector<int>::const_iterator i = alpha.begin(); i != alpha.end(); i++ ) {
    delta[ *i % base ].push_back( ( *i - *i % base ) / base );
  }
  
  alpha.clear();
  for( int i = 0; i < base; i++ ) {
    delta[ i ] = radixSort( delta[ i ], base, depth - 1 );
    //for( int k = delta[ i ].size() - 1; k >= 0; k-- ) {
    for( unsigned int k = 0; k < delta[ i ]. size(); k++ ) {
      alpha.push_back( delta[ i ][ k ] * base + i );
    }
  }

  return alpha;
}

#endif
