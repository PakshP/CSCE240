// Copyright 2024 bhipp
// initial tests for calls to PrintAsDollarsAndCents
#include<iostream>
using std::cout;
using std::endl;
#include"./program2functions.h"

int main() {
  PrintAsDollarsAndCents(2708);
  cout << endl;
  PrintAsDollarsAndCents(300);
  cout << endl;
  PrintAsDollarsAndCents(10042);
  cout << endl;
  PrintAsDollarsAndCents(312199);
  cout << endl;
  return 0;
}

