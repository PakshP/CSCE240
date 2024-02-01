// Copyright 2024 bhipp
// initial tests for LargestPrimeSequence
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"./program2functions.h"

int main() {
  int returned_value = LargestPrimeSequence(4);
  if ( LargestPrimeSequence(4) == -1 ) {
    cout << "Passed LargestPrimeSequence(4) test" << endl;
  } else {
    cout << "Failed LargestPrimeSequence(4) test. Returned " << returned_value
         << " (-1 expected)" << endl;
  }

  returned_value = LargestPrimeSequence(17);
  if ( LargestPrimeSequence(17) == 17 ) {
    cout << "Passed LargestPrimeSequence(17) test" << endl;
  } else {
    cout << "Failed LargestPrimeSequence(17) test. Returned " << returned_value
         << " (17 expected)" << endl;
  }

  returned_value = LargestPrimeSequence(248);
  if ( LargestPrimeSequence(248) == 2 ) {
    cout << "Passed LargestPrimeSequence(248) test" << endl;
  } else {
    cout << "Failed LargestPrimeSequence(248) test. Returned " << returned_value
         << " (2 expected)" << endl;
  }

  returned_value = LargestPrimeSequence(801302);
  if ( LargestPrimeSequence(801302) == 13 ) {
    cout << "Passed LargestPrimeSequence(801302) test" << endl;
  } else {
    cout << "Failed LargestPrimeSequence(801302) test. Returned "
         << returned_value << " (13 expected)" << endl;
  }

  returned_value = LargestPrimeSequence(293794);
  if ( LargestPrimeSequence(293794) == 937 ) {
    cout << "Passed LargestPrimeSequence(293794) test" << endl;
  } else {
    cout << "Failed LargestPrimeSequence(293794) test. Returned "
         << returned_value << " (937 expected)" << endl;
  }

  returned_value = LargestPrimeSequence(31131);
  if ( LargestPrimeSequence(31131) == 311 ) {
    cout << "Passed LargestPrimeSequence(31131) test" << endl;
  } else {
    cout << "Failed LargestPrimeSequence(31131) test. Returned "
         << returned_value << " (311 expected)" << endl;
  }

  return 0;
}
