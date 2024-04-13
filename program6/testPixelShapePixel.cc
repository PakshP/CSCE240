// Copyright 2024 bhipp
// Initial PixelShape pixel tests (before addition of pure virtual functions
#include<iostream>
using std::cout;
using std::endl;
#include"PixelShape.h"
using CSCE240_Program6::PixelShape;

int main() {
  PixelShape p;
  char pixel = p.GetPixel();
  if ( pixel == '*' ) {
    cout << "Passed default pixel test" << endl;
  } else {
    cout << "Failed default pixel test. GetPixel() returned " << pixel
         << " expected *" << endl;
  }

  p.SetPixel('t');
  pixel = p.GetPixel();
  if ( pixel == 't' ) {
    cout << "Passed SetPixel('t') test" << endl;
  } else {
    cout << "Failed SetPixel('t') test. GetPixel() returned " << pixel
         << " expected t" << endl;
  }

  char orig = pixel;
  p.SetPixel(' ');  // ' ' is an invalid pixel value, the pixel data member
                    // should remain unchanged.
  pixel = p.GetPixel();
  if ( pixel == orig ) {
    cout << "Passed SetPixel(' ') test" << endl;
  } else {
    cout << "Failed SetPixel(' ') test. GetPixel() returned " << pixel
         << " expected " << orig << endl;
  }

  PixelShape p2("square", '#');
  pixel = p2.GetPixel();
  if ( pixel == '#' ) {
    cout << "Passed constructor with '#' argument test" << endl;
  } else {
    cout << "Failed constructor with '#' argument test. "
         << "GetPixel() returned " << pixel << " expected #" << endl;
  }

  PixelShape p3("square", '\n');
  pixel = p3.GetPixel();
  if ( pixel == '*' ) {
    cout << "Passed constructor with '\\n' argument test" << endl;
  } else {
    cout << "Failed constructor with '\\n' argument test. "
         << "GetPixel() returned " << pixel << " expected *" << endl;
  }  return 0;
}
