#include <iostream>
#include <vector>

#include "HeapSort.h"

#include "BogoSort.h"

#include "BubbleSort.h"
#include "SelectionSort.h"

#include "QuickSort.h"

#include "StrandSort.h"
#include "CycleSort.h"

#include "MergeSort.h"
#include "InsertionSort.h"
#include "TimSort.h"

#include "RadixSort.h"

#include "BitonicSort.h"

#include "BucketSort.h"
#include "ShellSort.h"
#include "CombSort.h"
#include "GnomeSort.h"

using namespace std;

void Display( string name, const vector<int> a1 ) {
  cout<<name<<"\t";
  for( vector<int>::const_iterator i = a1.begin(); i != a1.end(); i++ ) {
    cout<<*i<<" "; 
  }
  cout<<endl<<endl;
}

int main() {
  vector<int> a1 = { 0, 2, 9, 6, 5, 3, 4, 8 };
  
  a1 = {};
  
  int d0 = 0;
  
  cin>>d0;
  
  for (int i = 0, d1; i < d0; i++) {
    cin>>d1;
    a1.push_back( d1 );
  }
  
  //a1 = { 4, 10, 3, 5, 1 };
  //a1 = { 7, 6, 9, 19, 17, 32, 10, 12, 13, 26, 11, 18, 27, 3, 28, 2 };
  //a1 = { 1, 1, 1, 1, 1, 1, 1, 1 };
  Display( "Baseline", a1 );
  cout<<"----------------------------------\n\n";
  Display( "Heap Sort", heapSort( a1 ) );
  Display( "Bubble Sort", bubbleSort( a1 ) );
  Display( "Selection Sort", selectionSort( a1 ) );
  Display( "Quick Sort", quickSort( a1 ) );
  Display( "Strand Sort", strandSort( a1 ) );
  Display( "Merge Sort", mergeSort( a1 ) );
  Display( "Insertion Sort", insertionSort( a1 ) );
  Display( "Tim Sort", timSort( a1 ) ); 
  Display( "Radix Sort", radixSort( a1, 2, 10 ) );
  //Display( "Cycle Sort", cycleSort( a1 ) );
  Display( "Bitonic Sort", bitonicSort( a1 ) );
  //Display( "Bogo Sort", bogoSort( a1 ) ); //Surprisingly, it takes ages. not adding it to default set
  Display( "Bucket Sort", bucketSort( a1, 10 ) );
  Display( "Shell Sort n / 2", shellSort( a1 ) );
  Display("Comb Sort", combSort( a1, 1.245 ) );
  Display( "Gnome Sort", gnomeSort( a1 ) );
}
