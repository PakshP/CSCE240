// Copyright 2024 bhipp
// Initial RightIsosceles *= operator test
#include<iostream>
using std::cout;
using std::endl;
#include"Rectangle.h"
using CSCE240_Program6::Rectangle;

int main() {
  int orig_length, new_length, orig_width, new_width;
  double factor;
  Rectangle r(3, 2);
  orig_length = r.GetLength();
  orig_width = r.GetWidth();
  factor = 3;
  r *= factor;
  new_length = r.GetLength();
  new_width = r.GetWidth();
  if ( 9 == new_length &&
       6 == new_width ) {
    cout << "Passed r *= " << factor << " test" << endl;
  } else {
    cout << "Failed r *= " << factor << " test. GetLength() returned "
         << new_length << " (expected 9) and GetWidth() returned " << new_width
         << " (expected 6)" << endl;
  }

  Rectangle r2(6, 5);
  orig_length = r2.GetLength();
  orig_width = r2.GetWidth();
  factor = 0.5;
  r2 *= factor;
  new_length = r2.GetLength();
  new_width = r2.GetWidth();
  if ( 3 == new_length &&
       2 == new_width ) {
    cout << "Passed r2 *= " << factor << " test" << endl;
  } else {
    cout << "Failed r2 *= " << factor << " test. GetLength() returned "
         << new_length << " (expected 3) and GetWidth() returned " << new_width
         << " (expected 2)" << endl;
  }

  Rectangle r3(5, 3);
  orig_length = r3.GetLength();
  orig_width = r3.GetWidth();
  factor = 0.3;
  r3 *= factor;  // can't make the width 0, so should leave the rectangle
                 // unchanged
  new_length = r3.GetLength();
  new_width = r3.GetWidth();
  if ( orig_length == new_length && orig_width == new_width ) {
    cout << "Passed r3 *= " << factor << " test" << endl;
  } else {
    cout << "Failed r3 *= " << factor << " test. GetLength() returned "
         << new_length << " (expected " << orig_length
         << ") and GetWidth() returned " << new_width
         << " (expected " << orig_width << ")" << endl;
  }
  return 0;
}
