// Copyright 2024 bhipp
// test MonetaryUnit class constructor
#include<iostream>
using std::cout;
using std::endl;
#include"MonetaryUnit.h"

int main() {
  const MonetaryUnit kM1;
  if ( kM1.GetName() == "US dollars" && kM1.GetSymbol() == "$" &&
       kM1.GetAmountEquivalentTo1Dollar() == 1 ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << kM1.GetName() <<  " - expected US dollars\n"
         << kM1.GetSymbol() << " - expected $\n"
         << kM1.GetAmountEquivalentTo1Dollar() << " - expected 1\n" << endl;
  }

  MonetaryUnit m2("Pesos");
  if ( m2.GetName() == "Pesos" && m2.GetSymbol() == "$" &&
       m2.GetAmountEquivalentTo1Dollar() == 1 ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << m2.GetName() <<  " - expected Pesos\n"
         << m2.GetSymbol() << " - expected $\n"
         << m2.GetAmountEquivalentTo1Dollar() << " - expected 1\n" << endl;
  }

  MonetaryUnit m3("Rupees", "\u20b9");
  if ( m3.GetName() == "Rupees" && m3.GetSymbol() == "\u20b9" &&
       m3.GetAmountEquivalentTo1Dollar() == 1 ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << m3.GetName() <<  " - expected Rupees\n"
         << m3.GetSymbol() << " - expected \u20b9\n"
         << m3.GetAmountEquivalentTo1Dollar() << " - expected 1\n" << endl;
  }

  MonetaryUnit m4("Euros", "\u20ac", 0.92);
  if ( m4.GetName() == "Euros" && m4.GetSymbol() == "\u20ac" &&
       m4.GetAmountEquivalentTo1Dollar() == 0.92 ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << m4.GetName() <<  " - expected Euros\n"
         << m4.GetSymbol() << " - expected \u20ac\n"
         << m4.GetAmountEquivalentTo1Dollar() << " - expected 0.92\n" << endl;
  }

  MonetaryUnit m5("Robux", "", -3);
  if ( m5.GetName() == "Robux" && m5.GetSymbol() == "$" &&
       m5.GetAmountEquivalentTo1Dollar() == 1 ) {
    cout << "Passed default constructor / accessor test" << endl;
  } else {
    cout << "Failed default constructor / accessor test\n"
         << m5.GetName() <<  " - expected Robux\n"
         << m5.GetSymbol() << " - expected $\n"
         << m5.GetAmountEquivalentTo1Dollar() << " - expected 1\n" << endl;
  }

  return 0;
}
