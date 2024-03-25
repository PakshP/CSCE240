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

  MonetaryAmount money1(1);
  money1.ConvertToUnit(kEuros);
  if ( money1.GetValue() == 0.92 && money1.GetUnit() == kEuros ) {
    cout << "Passed convert one dollar to euros test" << endl;
  } else {
    cout << "Failed convert one dollar to euros test\n"
         << money1.GetValue() << " - expected " << 0.92 << "\n"
         << money1.GetUnit().GetName() <<  " - expected Euros\n"
         << money1.GetUnit().GetSymbol() << " - expected \u20ac\n"
         << money1.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 0.92 << "\n" << endl;
  }

  MonetaryAmount money2(0.92, kEuros);
  money2.ConvertToUnit(dollars);
  if ( money2.GetValue() == 1 && money2.GetUnit() == dollars ) {
    cout << "Passed convert 0.92 euros to dollars test" << endl;
  } else {
    cout << "Failed convert 0.92 euros to dollars test\n"
         << money2.GetValue() << " - expected " << 1.0 << "\n"
         << money2.GetUnit().GetName() <<  " - expected US dollars\n"
         << money2.GetUnit().GetSymbol() << " - expected $\n"
         << money2.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 1 << "\n" << endl;
  }

  MonetaryAmount money3(82.85, kRupees);
  money3.ConvertToUnit(dollars);
  if ( money2.GetValue() == 1 && money2.GetUnit() == dollars ) {
    cout << "Passed convert 82.85 rupees to dollars test" << endl;
  } else {
    cout << "Failed convert 82.85 rupees to dollars test\n"
         << money3.GetValue() << " - expected " << 1 << "\n"
         << money3.GetUnit().GetName() <<  " - expected US dollars\n"
         << money3.GetUnit().GetSymbol() << " - expected $\n"
         << money3.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 1 << "\n" << endl;
  }

  return 0;
}
