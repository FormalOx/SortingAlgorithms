#ifndef CMMPI
#define CMMPI

#include <vector>

std::vector<int>  combSort( std::vector<int> a1, float a2 ) {
  bool    sorted = false;
  float   shrinkDelta = a2;
  
  while( !sorted ) {
    sorted = true;
    int distace = a1.size() / shrinkDelta;
 
    for( unsigned int deltaS, i = 0; i + distace < a1.size(); i++ ) {
      if( a1[ i ] > a1[ i + distace ] ) {
        sorted = false;
        deltaS = a1[ i ];
        a1[ i ] = a1[ i + distace ]; 
        a1[ i + distace ] = deltaS;
      }
    }
    
    shrinkDelta *= a2;
  }
  
  return a1;
}

#endif
