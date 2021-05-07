#ifndef CSMPI
#define CSMPI
#include <vector>

int posInVector ( const std::vector<int> alpha, int alpha2 ) {
  int cnt = 0;
  for( unsigned int i = 0; i < alpha.size(); i++ ) {
    if( alpha[ i ] < alpha2 ) {
      cnt++;
    }
  }
  return cnt;
}

struct ll {
  int v;
  ll* nx;
  ll ( ll* aNx ) { nx = aNx; }
  ll() { nx = 0; }
};

std::vector<int> cycleSort( std::vector<int> alpha ) {
  unsigned int d1;
  for( unsigned int i = 0; i < alpha.size(); i++ ) {
    d1 = posInVector( alpha, alpha[ i ] );
    if( d1 == i ) { continue; }
    ll *d3 = new ll();
    d3->v = i;
    while ( i != d1 ) {
      d3 = new ll( d3 );
      d3->v = d1;
      d1 = posInVector( alpha, alpha[ d1 ] );
    }
    int d2;
    d2 = alpha[ d3 -> v ];
    while( d3 -> nx != 0 ) {
      alpha[ d3 -> v ] = alpha[ d3 -> nx -> v ];
      d3 = d3 -> nx;
    }
    alpha[ d3 -> v ] = d2;
  }
  return alpha;
}

#endif
