// Copyright 2024 bhipp
// Initial PixelShape name tests (before addition of pure virtual functions
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
#include"PixelShape.h"
using CSCE240_Program6::PixelShape;

int main() {
  PixelShape p;
  string name = p.GetName();
  if ( name == "?" ) {
    cout << "Passed default name test" << endl;
  } else {
    cout << "Failed default name test. GetName() returned " << name
         << " expected ?" << endl;
  }

  p.SetName("circle");
  name = p.GetName();
  if ( name == "circle" ) {
    cout << "Passed SetName(\"circle\") test" << endl;
  } else {
    cout << "Failed SetName(\"circle\") test. GetName() returned " << name
         << " expected circle" << endl;
  }

  string orig = name;
  p.SetName("");  // ' ' is an invalid pixel value, the pixel data member
                    // should remain unchanged.
  name = p.GetName();
  if ( name == orig ) {
    cout << "Passed SetName(\"\") test" << endl;
  } else {
    cout << "Failed SetName(\"\") test. GetName() returned " << name
         << " expected " << orig << endl;
  }

  PixelShape p2("square");
  name = p2.GetName();
  if ( name == "square" ) {
    cout << "Passed constructor with \"square\" argument test" << endl;
  } else {
    cout << "Failed constructor with \"square\" argument test. "
         << "GetName() returned " << name << " expected square" << endl;
  }

  PixelShape p3("");
  name = p3.GetName();
  if ( name == "?" ) {
    cout << "Passed constructor with \"\" argument test" << endl;
  } else {
    cout << "Failed constructor with \"\" argument test. "
         << "GetName() returned " << name << " expected ?" << endl;
  }
  return 0;
}
