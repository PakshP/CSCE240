// Copyright 2024 bhipp
// Test virtual Print functions for PixelShape child classes RightIsosceles
// and Rectangle
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include"PixelShape.h"
#include"Rectangle.h"
#include"RightIsosceles.h"
using CSCE240_Program6::PixelShape;
using CSCE240_Program6::RightIsosceles;
using CSCE240_Program6::Rectangle;

int main(int argc, char *argv[]) {
  double factor = 2;
  bool show_interior = true;
  if ( argc >= 2 ) {
    factor = atof(argv[1]);
  }
  if ( argc >= 3 ) {
    show_interior = argv[2][0] == 't';
  }

  int size = 1, i = 0;
  PixelShape * * ptr = new PixelShape * [size];
  string which;
  int l, w;
  char p;
  cin >> which;
  while ( which == "rectangle" || which == "triangle" ) {
    if ( i + 1 == size ) {
      PixelShape * * temp = ptr;
      ptr = new PixelShape * [size * 2];
      for ( int j = 0; j < size; ++j )
        ptr[j] = temp[j];
      delete [] temp;
      size *= 2;
    }
    if ( which == "triangle" ) {
      cin >> l >> p;
      ptr[i] = new RightIsosceles(l, p);
    } else {
      cin >> l >> w >> p;
      ptr[i] = new Rectangle(l, w, p);
    }
    ++i;
    cin >> which;
  }

  for ( int k = 0; k < i; ++k ) {
    cout << "original" << endl;
    ptr[k]->Print(show_interior);
    cout << "times " << factor << endl;
    (*ptr[k]) *= factor;
    ptr[k]->Print(show_interior);
  }

  for ( int k = 0; k < i; ++k )
    delete ptr[k];
  delete [] ptr;
  ptr = nullptr;

  return 0;
}
