#ifndef SHMPI
#define SHMPI

#include <vector>

unsigned int BasicInterval( int k, int n ) {
  for( int i = 0; i < k; i++ ) {
    n /= 2;
  }
  if( n < 1 ) { return 1; }
  return n; 
}

unsigned int KnuthInterval( int k, int n ) {
  int omega = 1;
  for( int i = 0; i < k; i++ ) { omega *= 3; }
  return ( omega - 1 ) / 2;
}

unsigned int ( *Itvf ) ( int, int ) = BasicInterval;
//unsigned int ( *Itvf ) ( int, int ) = KnuthInterval;

int   reversed = 0; //reverse 1 for knuth, although it's buggy

std::vector<int> shellSort ( std::vector<int> a1 ) {
  //std::cout<<"!!!\n";
  
  int savedI = 1;
  
  for( unsigned int pastV = 0; Itvf( savedI, a1.size() ) < a1.size() && Itvf( savedI, a1.size() ) != pastV; savedI++ ) { pastV = Itvf( savedI, a1.size() ); }
  
  for( int delta1, delta2, i = 1 + ( savedI - 2 ) * reversed; i != savedI && i != 0; i -= 2 * reversed - 1 ) {
    delta1 = Itvf( i, a1.size() );
    
    //std::cout<<"! "<<i<<" "<<delta1<<"\n\n";
    
    for( unsigned int k = 0; k + delta1 < a1.size(); k++ ) {
      //std::cout<<a1 [ k ]<<" "<<a1[ k + delta1];
      if ( a1[ k ] > a1[ k + delta1 ] ) {
        //std::cout<<" !!";
        delta2 = a1[ k ];
        a1[ k ] = a1[ k + delta1 ];
        a1[ k + delta1 ] = delta2;
      }
      //std::cout<<"\n";
    }
  }
  
  return a1;
}

#endif
