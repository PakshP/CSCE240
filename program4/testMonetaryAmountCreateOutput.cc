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

  const MonetaryUnit kDollarUnit;
  const MonetaryUnit kEuroUnit("Euros", "\u20ac", 0.92);
  const MonetaryUnit kRupeeUnit("Rupees", "\u20b9", 82.85);

  const MonetaryAmount kDollar(1), kEuroEquiv(0.92, kEuroUnit),
        kRupeeEquiv(82.85, kRupeeUnit);

  cout << kDollar << "\n"  << kEuroEquiv << "\n" << kRupeeEquiv << endl;

  MonetaryAmount::display_unit_name = true;

  cout << kDollar << "\n"  << kEuroEquiv << "\n" << kRupeeEquiv << endl;

  return 0;
}
