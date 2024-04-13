// Copyright 2024 bhipp
// Initial RightIsosceles *= operator test
#include<iostream>
using std::cout;
using std::endl;
#include"RightIsosceles.h"
using CSCE240_Program6::RightIsosceles;

int main() {
  int orig_leg, new_leg;
  double factor;
  RightIsosceles t(3);
  orig_leg = t.GetLeg();
  factor = 4;
  t *= factor;
  new_leg = t.GetLeg();
  if ( orig_leg * factor == new_leg ) {
    cout << "Passed t *= " << factor << " test" << endl;
  } else {
    cout << "Failed t *= " << factor << " test. GetLeg() returned "
         << new_leg << " expected " << orig_leg * factor << endl;
  }

  RightIsosceles t2(8);
  orig_leg = t2.GetLeg();
  factor = 0.5;
  t2 *= factor;
  new_leg = t2.GetLeg();
  if ( orig_leg * factor == new_leg ) {
    cout << "Passed t2 *= " << factor << " test" << endl;
  } else {
    cout << "Failed t2 *= " << factor << " test. GetLeg() returned "
         << new_leg << " expected " << orig_leg * factor << endl;
  }

  RightIsosceles t3(8);
  orig_leg = t3.GetLeg();
  factor = 0.1;
  t3 *= factor;  // can't make legs of the triangle 0, triangle should
                 // remain unchanged
  new_leg = t3.GetLeg();
  if ( orig_leg == new_leg ) {
    cout << "Passed t3 *= " << factor << " test" << endl;
  } else {
    cout << "Failed t3 *= " << factor << " test. GetLeg() returned "
         << new_leg << " expected " << orig_leg * factor << endl;
  }
  return 0;
}
