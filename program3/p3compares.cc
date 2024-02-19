// Copyright 2024 bhipp
#include"p3compares.h"
#include<iostream>
using std::cout;
using std::endl;

// pre-condition: expected and actual are integer arrays of the same size
double PercentMatch(const int expected[], const int actual[], int size) {
  int match = 0;
  for ( int i = 0; i < size; ++i ) {
    cout << actual[i];
    if ( expected[i] == actual[i] )
      ++match;
    else
      cout << "(expected " << expected[i] << ")";
    cout << " ";
  }
  cout << endl;
  return 100 * match / static_cast<double>(size);
}

// preconditions: expected and actual are character arrays of the same size
//                the expected array contains a null character terminating
//                the cstring
double PercentMatch(const char expected[], const char actual[]) {
  int match = 0, i = 0;
  cout << "Actual:\n";
  while ( expected[i] != '\0' ) {
    cout << actual[i];
    if ( expected[i] == actual[i] )
      ++match;
    ++i;
  }
  if ( actual[i++] == '\0' )
    ++match;
  if ( i != match )
    cout << "\nExpected:\n" << expected;
  cout << endl;
  return 100 * match / static_cast<double>(i);
}

// preconditions: expected and actual are square integer arrays with
//                kSquareSize rows and kSquareSize columns
double PercentMatch(const int expected[][kSquareSize],
                    const int actual[][kSquareSize]) {
  int match = 0;
  for ( int i = 0; i < kSquareSize; ++i ) {
    for ( int j = 0; j < kSquareSize; ++j ) {
      cout << actual[i][j];
      if ( expected[i][j] == actual[i][j] )
        ++match;
      else
        cout << "(expected " << expected[i][j] << ")";
      cout << " ";
    }
    cout << endl;
  }
  return 100 * match / static_cast<double>(kSquareSize * kSquareSize);
}
