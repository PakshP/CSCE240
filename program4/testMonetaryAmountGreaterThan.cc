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

  if ( kDollar > kEuroEquiv ) {
    cout << "Failed 1 dollar > 0.92 euros test\n" << endl;
  } else {
    cout << "Passed 1 dollar > 0.92 euros test" << endl;
  }

  if ( kDollar > kRupeeEquiv ) {
    cout << "Failed 1 dollar > 82.85 rupees test\n" << endl;
  } else {
    cout << "Passed 1 dollar > 82.85 rupees test" << endl;
  }

  if ( kEuroEquiv > kRupeeEquiv ) {
    cout << "Failed 0.92 euros > 82.85 rupees test\n" << endl;
  } else {
    cout << "Passed 0.92 euros > 82.85 rupees test" << endl;
  }

  MonetaryAmount threeDollars(3), threeEuros(3, kEuros);
  if ( threeEuros > threeDollars ) {
    cout << "Passed 3 euros > 3 dollars test" << endl;
  } else {
    cout << "Failed 3 euros > 3 dollars test\n" << endl;
  }

  if ( threeDollars > kRupeeEquiv ) {
    cout << "Passed 3 dollars test > 82.85 rupees" << endl;
  } else {
    cout << "Failed 3 dollars test > 82.85 rupees\n" << endl;
  }

  return 0;
}
