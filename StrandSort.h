#ifndef STSMPI
#define STSMPI
#include <vector>

std::vector<int> strandSort( std::vector<int> a1 ) {
  std::vector<int> omega;
  std::vector<int> delta;
  std::vector<int> delta2;
  
  unsigned int k1, k2;
  
  while ( a1.size() != 0 ) {
    
    delta.push_back( a1[ 0 ] );
    a1.erase( a1.begin() );
    
    for( unsigned int k = 0; k < a1.size(); k++ ) {
      if( delta[ delta.size() - 1 ] < a1[ k ] ) {
        delta.push_back( a1[ k ] );
        a1.erase( a1.begin() + k );
      }
    }
    
    //Merging
    
    k1 = 0; k2 = 0;
    for( ; k1 < delta.size() && k2 < omega.size(); ) {
      if( delta[ k1 ] < omega[ k2 ] ) {
        delta2.push_back( delta[ k1++ ] );
      } else {
        delta2.push_back( omega[ k2++ ] );
      }
    }
    for( ; k1 < delta.size(); k1++ ) {
      delta2.push_back( delta[ k1 ] );
    }
    for( ; k2 < omega.size(); k2++ ) {
      delta2.push_back( omega[ k2 ] );
    }
    omega = delta2;
    delta.clear(); 
    delta2.clear();
  }
  
  return omega;
}

#endif
