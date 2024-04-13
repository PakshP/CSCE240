// Copyright 2024 bhipp
// Initial RightIsosceles name test
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"RightIsosceles.h"
using CSCE240_Program6::RightIsosceles;

int main() {
  RightIsosceles t;
  string name = t.GetName();
  if ( name == "right isosceles triangle" ) {
    cout << "Passed default name test" << endl;
  } else {
    cout << "Failed default name test. GetName() returned " << name
         << " expected right isosceles triangle" << endl;
  }
  return 0;
}
