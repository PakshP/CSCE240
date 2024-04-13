// Copyright 2024 bhipp
// Initial RightIsosceles leg data member constructor, mutator,
// and accessor tests
#include<iostream>
using std::cout;
using std::endl;
#include"RightIsosceles.h"
using CSCE240_Program6::RightIsosceles;

int main() {
  RightIsosceles t;
  int leg = t.GetLeg();
  if ( leg == 2 ) {
    cout << "Passed default leg test" << endl;
  } else {
    cout << "Failed default leg test. GetLeg() returned " << leg
         << " expected 2" << endl;
  }

  t.SetLeg(7);
  leg = t.GetLeg();
  if ( leg == 7 ) {
    cout << "Passed SetLeg(7) test" << endl;
  } else {
    cout << "Failed SetLeg(7) test. GetLeg() returned " << leg
         << " expected 7" << endl;
  }

  int orig = leg;
  t.SetLeg(0);  // 0 is an invalid leg value, the leg data member
                // should remain unchanged.
  leg = t.GetLeg();
  if ( leg == orig ) {
    cout << "Passed SetLeg(0) test" << endl;
  } else {
    cout << "Failed SetLeg(0) test. GetLeg() returned " << leg
         << " expected " << orig << endl;
  }

  RightIsosceles t2(5);
  leg = t2.GetLeg();
  if ( leg == 5 ) {
    cout << "Passed constructor with 5 as argument test" << endl;
  } else {
    cout << "Failed constructor with 5 as argument test. "
         << "GetLeg() returned " << leg << " expected 5" << endl;
  }

  RightIsosceles t3(1);
  leg = t3.GetLeg();
  if ( leg == 2 ) {
    cout << "Passed constructor with 1 as argument test" << endl;
  } else {
    cout << "Failed constructor with 1 as argument test. "
         << "GetLeg() returned " << leg << " expected 2" << endl;
  }
  return 0;
}
