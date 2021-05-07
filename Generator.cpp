#include <iostream>
#include <stdlib.h>

using namespace std;

int cati( char* a1 ) {  //Char array to int
  int res = 0;
  for( int i = 0; a1[ i ] != 0; i++ ) {
    res *= 10;
    res += a1[ i ] - '0';
  }
  return res;
}

int main( int argc, char **argv ) {
  if( argc == 1 ) {
    return 0;
  }
  int lgt = cati( argv[ 1 ] );
  if( argc == 3 ) {
    srand( cati( argv[ 2 ] ) );
  }
  
  bool unique = false;
  int d;
  const int range = 300768;
  int chk[ range ];
  for( int i = 0; i < range; i++ ) { chk[ i ] = 0; }
  
  if( unique && range <= lgt ) {
    cout<<"Bakanai!\n";
    return 0;
  }
  
  cout<<lgt<<" ";
  while( lgt-- != 0 ) {
    d = rand() % range;
    if( unique && chk[ d ] == 1 ) {
      lgt++;
    } else {
      cout<<d<<" ";
      chk[ d ] = 1;
    }
  }
  cout<<"\n";
  
}
