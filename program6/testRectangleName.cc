// Copyright 2024 bhipp
// Initial Rectangle name test
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"Rectangle.h"
using CSCE240_Program6::Rectangle;

int main() {
  Rectangle r;
  string name = r.GetName();
  if ( name == "rectangle" ) {
    cout << "Passed default name test" << endl;
  } else {
    cout << "Failed default name test. GetName() returned " << name
         << " expected rectangle" << endl;
  }
  return 0;
}
