// Copyright 2024 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include<iomanip>
using std::setprecision;
using std::setiosflags;
#include"MonetaryUnit.h"
#include"MonetaryAmount.h"

int main() {
  cout << setiosflags(std::ios::fixed) << setprecision(2);
  MonetaryUnit dollars;
  const MonetaryUnit kEuros("Euros", "\u20ac", 0.92);
  const MonetaryUnit kRupees("Rupees", "\u20b9", 82.85);

  const MonetaryAmount kDollar(1), kEuroEquiv(0.92, kEuros),
        kRupeeEquiv(82.85, kRupees);

  if ( kDollar == kEuroEquiv ) {
    cout << "Passed 1 dollar == 0.92 euros test" << endl;
  } else {
    cout << "Failed 1 dollar == 0.92 euros test\n" << endl;
  }

  if ( kDollar == kRupeeEquiv ) {
    cout << "Passed 1 dollar == 82.85 rupees test" << endl;
  } else {
    cout << "Failed 1 dollar == 82.85 rupees test\n" << endl;
  }

  if ( kEuroEquiv == kRupeeEquiv ) {
    cout << "Passed 0.92 euros == 82.85 rupees test" << endl;
  } else {
    cout << "Failed 0.92 euros == 82.85 rupees test\n" << endl;
  }

  MonetaryAmount threeDollars(3), threeEuros(3, kEuros);
  if ( threeDollars == threeEuros ) {
    cout << "Failed 3 dollars == 3 euros test\n" << endl;
  } else {
    cout << "Passed 3 dollars == 3 euros test" << endl;
  }

  if ( kDollar == threeDollars ) {
    cout << "Failed 1 dollar == 3 dollars test\n" << endl;
  } else {
    cout << "Passed 1 dollar == 3 dollars test" << endl;
  }

  return 0;
}
