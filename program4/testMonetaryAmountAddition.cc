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
  const MonetaryUnit kCentUnit("US cents", "\u00a2", 100);

  const MonetaryAmount kDollar(1), kEuroEquiv(0.92, kEuroUnit),
        kRupeeEquiv(82.85, kRupeeUnit), kCent(1, kCentUnit);

  MonetaryAmount answer1 = kDollar + kEuroEquiv;
  if ( answer1.GetValue() == 2 && answer1.GetUnit() == kDollarUnit ) {
    cout << "Passed 1 US dollar + 0.92 euros = 2 US dollars test" << endl;
  } else {
    cout << "Failed 1 US dollar + 0.92 euros = 2 US dollars test\n"
         << answer1.GetValue() << " - expected " << 2.0 << "\n"
         << answer1.GetUnit().GetName() <<  " - expected US dollars\n"
         << answer1.GetUnit().GetSymbol() << " - expected $\n"
         << answer1.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 1.0 << endl;
  }

  MonetaryAmount answer2 = kCent + kDollar;
  if ( answer2.GetValue() == 101 && answer2.GetUnit() == kCentUnit ) {
    cout << "Passed 101 US cents + 1 US dollar = 101 US cents test" << endl;
  } else {
    cout << "Failed 101 US cents + 1 US dollar = 101 US cents test\n"
         << answer2.GetValue() << " - expected " << 101.0 << "\n"
         << answer2.GetUnit().GetName() <<  " - expected US cents\n"
         << answer2.GetUnit().GetSymbol() << " - expected \u00a2\n"
         << answer2.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 100.0 << endl;
  }

  MonetaryAmount answer3 = kDollar + kCent;
  if ( answer3.GetValue() == 1.01 && answer3.GetUnit() == kDollarUnit ) {
    cout << "Passed 1 US dollar + 101 US cents = 1.01 US dollars test" << endl;
  } else {
    cout << "Passed 1 US dollar + 101 US cents = 1.01 US dollars test\n"
         << answer3.GetValue() << " - expected " << 1.01 << "\n"
         << answer3.GetUnit().GetName() <<  " - expected US dollars\n"
         << answer3.GetUnit().GetSymbol() << " - expected $\n"
         << answer3.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 1.01 << endl;
  }

  MonetaryAmount answer4 = kRupeeEquiv + kDollar;
  if ( answer4.GetValue() == 165.7 && answer4.GetUnit() == kRupeeUnit ) {
    cout << "Passed 1 US dollar + 101 US cents = 1.01 US dollars test" << endl;
  } else {
    cout << "Passed 1 US dollar + 101 US cents = 1.01 US dollars test\n"
         << answer4.GetValue() << " - expected " << 165.7 << "\n"
         << answer4.GetUnit().GetName() <<  " - expected Rupees\n"
         << answer4.GetUnit().GetSymbol() << " - expected \u20b9\n"
         << answer4.GetUnit().GetAmountEquivalentTo1Dollar()
         << " - expected " << 82.85 << endl;
  }
  return 0;
}
