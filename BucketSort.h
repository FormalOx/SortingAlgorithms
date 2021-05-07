#ifndef BKMPI 
#define BKMPI 

#include <vector>

struct BKT {
  float v;
  BKT* nx;
  BKT() { nx = nullptr; }
  BKT( BKT* aNx ) { nx = aNx; }
};

std::vector<int>  bucketSort( std::vector<int> a1, int nB ) {
  if( nB <= 0 ) { return a1; }
  
  int mx = -1, mn = -1;
  
  for( unsigned int i = 0; i < a1.size(); i++ ) {
    if( a1[ i ] > mx ) {
      mx = a1[ i ];
    } else {
      if( mn == -1 || a1[ i ] < mn ) {
        mn = a1[ i ];
      }
    }
  }
  
  if( mn == mx ) {
    return a1;
  }
  
  BKT* delta[ nB + 1 ];
  
  for( int i = 0; i <= nB; i++ ) {
    delta[ i ] = 0;
  }
  
  float step = ( mx - mn ) / nB; 
  int   delta2;
  
  for( unsigned int i = 0; i < a1.size(); i++ ) {
    delta2 = ( ( a1[ i ] - mn + step ) / step ) - 1;
    //std::cout<<delta2<<" "<<a1[ i ]<<"\n";
    delta[ delta2 ] = new BKT( delta[ delta2 ] ); 
    delta[ delta2 ]->v = a1[ i ];
  }
  
  std::vector<int>  omega = std::vector<int>();
  
  for( int i = 0; i <= nB; i++ ) {
    bool sorted = false;

    BKT*  delta3;
    int   delta4;

    while( !sorted ) {
      sorted = true;
      delta3 = delta[ i ];
      while( delta3 != 0 && delta3->nx != 0 ) {
        //std::cout<<delta3->v<<"\n";
        if( delta3->v > delta3->nx->v ) {
          delta4 = delta3->v;
          delta3->v = delta3->nx->v;
          delta3->nx->v = delta4;
          sorted = false;
        }
        delta3 = delta3->nx;
      }
    }
    
    delta3 = delta[ i ];
     
    //std::cout<<"!!\n";
     
    while ( delta3 != 0 ) {
      omega.push_back( delta3->v );
      delta3 = delta3->nx;
    }
     
  }
  
  return omega;
} 

#endif
