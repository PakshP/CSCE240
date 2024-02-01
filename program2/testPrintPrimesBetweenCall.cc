// Copyright 2024 bhipp
// initial tests for calls to PrintPrimesBetween
#include<iostream>
using std::cout;
using std::endl;
#include"./program2functions.h"

int main() {
  PrintPrimesBetween(2, 3);
  cout << endl;
  PrintPrimesBetween(2, 3, true);
  cout << endl;
  PrintPrimesBetween(4, 17);
  cout << endl;
  PrintPrimesBetween(4, 17, true);
  cout << endl;
  return 0;
}

