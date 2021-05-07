/*
  ID     : 00?
  NAME   : Quick Sort
  DATE   : 7 mar
  TYPE   : U
*/
#ifndef QSMPI
#define QSMPI
#include <vector>

std::vector<int> quickSort( std::vector<int> alpha ) {
  if( alpha.size() < 2 ) {
    return alpha;
  }
  
  //std::cout<<alpha.size()<<std::endl;
 
  int pivot = alpha[ alpha.size() / 2 ];
 
  std::vector<int> dLow, dHigh;
 
  for( unsigned int i = 0; i < alpha.size(); i++ ) {
    if( i == alpha.size() / 2 ) continue;
    if( alpha[ i ] > pivot ) {
      dHigh.push_back( alpha[ i ] );
    } else {
      dLow.push_back( alpha[ i ] );
    }
  }
 
  //std::cout<<dHigh.size()<<" "<<pivot<<" !!!\n";
  //std::cin>>pivot;
  
  dHigh   = quickSort( dHigh );
  dLow    = quickSort( dLow );
  
  alpha.clear();
  alpha.insert( alpha.begin(), dLow.begin(), dLow.end() );
  alpha.push_back( pivot );
  alpha.insert( alpha.end(), dHigh.begin(), dHigh.end() );
  return alpha;
}

#endif
