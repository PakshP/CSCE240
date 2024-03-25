// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include"MonetaryUnit.h"

int main() {
  MonetaryUnit m1;
  if ( m1.SetAmountEquivalentTo1Dollar(0.5) && 
       m1.GetAmountEquivalentTo1Dollar() == 0.5 ) {
    cout << "Passed SetAmountEquivalentTo1Dollar(0.5) test" << endl;
  } else {
    cout << "Failed SetAmountEquivalentTo1Dollar(0.5) test\n" << endl;
  }

  MonetaryUnit m2;
  if ( m2.SetAmountEquivalentTo1Dollar(100) && 
       m2.GetAmountEquivalentTo1Dollar() == 100 ) {
    cout << "Passed SetAmountEquivalentTo1Dollar(100) test" << endl;
  } else {
    cout << "Failed SetAmountEquivalentTo1Dollar(100) test\n" << endl;
  }

  MonetaryUnit m3;
  if ( !m3.SetAmountEquivalentTo1Dollar(0) && 
       m3.GetAmountEquivalentTo1Dollar() == 1 ) {
    cout << "Passed SetAmountEquivalentTo1Dollar(0) test" << endl;
  } else {
    cout << "Failed SetAmountEquivalentTo1Dollar(0) test\n" << endl;
  }

  MonetaryUnit m4;
  if ( !m4.SetAmountEquivalentTo1Dollar(-0.3) && 
       m4.GetAmountEquivalentTo1Dollar() == 1 ) {
    cout << "Passed SetAmountEquivalentTo1Dollar(-0.3) test" << endl;
  } else {
    cout << "Failed SetAmountEquivalentTo1Dollar(-0.3) test\n" << endl;
  }
  return 0;
}
