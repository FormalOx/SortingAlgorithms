#ifndef BTMPI
#define BTMPI

#include <vector>
#include <iostream>

long smp2( long a1 ) {
  long s = 1;
  while ( s < a1 ) {
    s *= 2;
  }
  return s;
}

void bs ( int* a1, int s, int polarity ) {
  if( s < 2 ) return;
  int dsp = s / 2;
  int delta;
  for( int i = 0; i < dsp; i++ ) {
    if( a1[ i ] * polarity > a1[ i + dsp ] * polarity ) {
      delta = a1[ i ];
      a1[ i ] = a1[ i + dsp ];
      a1[ i + dsp ] = delta;
    }
  }
  bs( a1, s / 2, polarity );
  bs( a1 + s / 2, s / 2, polarity );
}

std::vector<int> bitonicSort( std::vector<int> alpha ) {
  const long size = alpha.size();
  if( size != smp2( alpha.size() ) ) {
    std::cout<<smp2( alpha.size() )<<" ERROR\n";
    return alpha;
  }
  
  static int d[ 16777216 * 8 ];
  
  for( int i = 0; i < size; i++ ) {
    d[ i ] = alpha[ i ];
  }
  
  for( int i = 2; i <= size; i *= 2 ) {
    for( int k = 0; k < size; k += i ) {
      bs( d + k, i, k / i % 2 == 1 ? -1 : 1 );
    }
  }
  
  for( int i = 0; i < size; i++ ) {
    alpha[ i ] = d[ i ];
  }
      
  return alpha;
  
}

#endif
