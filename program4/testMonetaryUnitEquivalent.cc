// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"MonetaryUnit.h"

int main() {
  MonetaryUnit m1, m2("US dollars", "$", 1), m3("cash", "$", 1),
               m4("US dollars", "*", 1), m5("US dollars", "$", 0.9);
  if ( m1 == m2 ) {
    cout << "Passed == true test" << endl;
  } else {
    cout << "Failed == true test\n" << endl;
  }

  if ( m2 == m3 ) {
    cout << "Failed == mismatched name test\n" << endl;
  } else {
    cout << "Passed == mismatched name test" << endl;
  }

  if ( m2 == m4 ) {
    cout << "Failed == mismatched symbol test\n" << endl;
  } else {
    cout << "Passed == mismatched symbol test" << endl;
  }

  if ( m2 == m5 ) {
    cout << "Failed == mismatched equivalent to dollar test\n" << endl;
  } else {
    cout << "Passed == mismatched equivalent to dollar test" << endl;
  }

  return 0;
}
