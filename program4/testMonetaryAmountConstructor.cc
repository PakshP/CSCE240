// Copyright 2024 bhipp
// test MonetaryAmount class constructor and accessor functions
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
  const MonetaryUnit kDollars;
  const MonetaryAmount kMoney1;
  if ( kMoney1.GetValue() == 0 && kMoney1.GetUnit() == kDollars ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << kMoney1.GetValue() << " - expected " << 0 << "\n"
         << kMoney1.GetUnit().GetName() <<  " - expected US dollars\n"
         << kMoney1.GetUnit().GetSymbol() << " - expected $\n"
         << kMoney1.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 1.0 << "\n" << endl;
  }

  const MonetaryAmount kMoney2(1.25);
  if ( kMoney2.GetValue() == 1.25 && kMoney2.GetUnit() == kDollars ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << kMoney2.GetValue() << " - expected " << 1.25 << "\n"
         << kMoney2.GetUnit().GetName() <<  " - expected US dollars\n"
         << kMoney2.GetUnit().GetSymbol() << " - expected $\n"
         << kMoney2.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 1.0 << "\n" << endl;
  }

  const MonetaryUnit kEuros("Euros", "\u20ac", 0.92);
  const MonetaryAmount kMoney3(1.84, kEuros);
  if ( kMoney3.GetValue() == 1.84 && kMoney3.GetUnit() == kEuros ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << kMoney3.GetValue() << " - expected " << 1.84 << "\n"
         << kMoney3.GetUnit().GetName() <<  " - expected US dollars\n"
         << kMoney3.GetUnit().GetSymbol() << " - expected \u20ac\n"
         << kMoney3.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 0.92 << "\n" << endl;
  }

  return 0;
}
