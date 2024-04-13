// Copyright 2024 bhipp
// Initial Rectangle leg data member constructor, mutator,
// and accessor tests
#include<iostream>
using std::cout;
using std::endl;
#include"Rectangle.h"
using CSCE240_Program6::Rectangle;

int main() {
  int length, width, original_length, original_width;
  Rectangle r;
  length = r.GetLength();
  width = r.GetWidth();
  if ( length == 2 && width == 1 ) {
    cout << "Passed default length and width test" << endl;
  } else {
    cout << "Failed default length and width test. GetLength() returned "
         << length << " (expected 2) and GetWidth() returned " << width
         << " (expected 1)" << endl;
  }

  r.SetLength(5);
  r.SetWidth(7);
  length = r.GetLength();
  width = r.GetWidth();
  if ( length == 5 && width == 7 ) {
    cout << "Passed set length and width to good values test" << endl;
  } else {
    cout << "Failed set length and width to good values test. GetLength()"
         << " returned " << length << " (expected 5) and GetWidth() returned "
         << width << " (expected 7)" << endl;
  }

  original_width = width;
  r.SetLength(1);
  r.SetWidth(0);  // invalid width, width should be unchanged
  length = r.GetLength();
  width = r.GetWidth();
  if ( length == 1 && width == original_width ) {
    cout << "Passed set length to good and width to bad value test" << endl;
  } else {
    cout << "Failed set length to good and width to bad value test. GetLength()"
         << " returned " << length << " (expected 1) and GetWidth() returned "
         << width << " (expected " << original_width << ")" << endl;
  }

  original_length = length;
  r.SetLength(-5);  // invalid length, length should be unchanged
  r.SetWidth(3);
  length = r.GetLength();
  width = r.GetWidth();
  if ( length == original_length && width == 3 ) {
    cout << "Passed set length to good and width to bad value test" << endl;
  } else {
    cout << "Failed set length to good and width to bad value test. GetLength()"
         << " returned " << length << " (expected " << original_length
         << ") and GetWidth() returned " << width << " (expected 3)" << endl;
  }

  Rectangle r2(8);
  length = r2.GetLength();
  width = r2.GetWidth();
  if ( length == 8 && width == 1 ) {
    cout << "Passed constructor with one argument test" << endl;
  } else {
    cout << "Failed constructor with one argument test. GetLength() returned "
         << length << " (expected 8) and GetWidth() returned " << width
         << " (expected 1)" << endl;
  }

  Rectangle r3(1, 4);
  length = r3.GetLength();
  width = r3.GetWidth();
  if ( length == 1 && width == 4 ) {
    cout << "Passed constructor with two good arguments test" << endl;
  } else {
    cout << "Failed constructor with two good arguments test. GetLength() "
         << "returned " << length << " (expected 1) and GetWidth() returned "
         << width << " (expected 4)" << endl;
  }

  Rectangle r4(0, 9);
  length = r4.GetLength();
  width = r4.GetWidth();
  if ( length == 2 && width == 9 ) {
    cout << "Passed constructor with one good and one bad argument test"
         << endl;
  } else {
    cout << "Failed constructor with one good and one bad argument test. "
         << "GetLength() returned " << length << " (expected 1) and "
         << "GetWidth() returned " << width
         << " (expected 4)" << endl;
  }

  return 0;
}
