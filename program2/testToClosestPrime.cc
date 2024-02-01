// Copyright 2024 bhipp
// initial tests for ToClosestPrime
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"./program2functions.h"

int main() {
  int returned_value = ToClosestPrime(10);
  if ( ToClosestPrime(10) == 1 ) {
    cout << "Passed ToClosestPrime(10) test" << endl;
  } else {
    cout << "Failed ToClosestPrime(10) test. Returned " << returned_value
         << " (1 expected)" << endl;
  }

  returned_value = ToClosestPrime(117);
  if ( ToClosestPrime(117) == -4 ) {
    cout << "Passed ToClosestPrime(117) test" << endl;
  } else {
    cout << "Failed ToClosestPrime(117) test. Returned " << returned_value
         << " (-4 expected)" << endl;
  }

  returned_value = ToClosestPrime(9);
  if ( ToClosestPrime(9) == 2 ) {
    cout << "Passed ToClosestPrime(9) test" << endl;
  } else {
    cout << "Failed ToClosestPrime(9) test. Returned " << returned_value
         << " (2 expected)" << endl;
  }

  returned_value = ToClosestPrime(41);
  if ( ToClosestPrime(41) == 0 ) {
    cout << "Passed ToClosestPrime(41) test" << endl;
  } else {
    cout << "Failed ToClosestPrime(41) test. Returned " << returned_value
         << " (0 expected)" << endl;
  }
  return 0;
}
