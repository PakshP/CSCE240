// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"MonetaryUnit.h"

int main() {
  MonetaryUnit m1;
  if ( m1.SetName("hello") && m1.GetName() == "hello" ) {
    cout << "Passed SetName(\"hello\") test" << endl;
  } else {
    cout << "Failed SetName(\"hello\") test\n" << endl;
  }

  MonetaryUnit m2;
  if ( !m2.SetName("") && m2.GetName() == "US dollars" ) {
    cout << "Passed SetName(\"\") test" << endl;
  } else {
    cout << "Failed SetName(\"\") test\n" << endl;
  }

  return 0;
}
