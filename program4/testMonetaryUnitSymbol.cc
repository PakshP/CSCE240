// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"MonetaryUnit.h"

int main() {
  MonetaryUnit m1;
  if ( m1.SetSymbol("hello") && m1.GetSymbol() == "hello" ) {
    cout << "Passed SetSymbol(\"hello\") test" << endl;
  } else {
    cout << "Failed SetSymbol(\"hello\") test\n" << endl;
  }

  MonetaryUnit m2;
  if ( !m2.SetSymbol("") && m2.GetSymbol() == "$" ) {
    cout << "Passed SetSymbol(\"\") test" << endl;
  } else {
    cout << "Failed SetSymbol(\"\") test\n" << endl;
  }

  return 0;
}
