// Copyright 2024 Paksh Patel
#ifndef _MONETARYUNIT_H_
#define _MONETARYUNIT_H_
#include<iostream>
#include<string>
using std::string;

class MonetaryUnit {
 public:
  // Constructor with optional parameters for name, symbol, and amount
  explicit MonetaryUnit(string name = "US dollars",
  string symbol = "$", double amount = 1);

  // Default destructor
  ~MonetaryUnit() {}

  // Setters for unit properties
  bool SetName(string name);
  bool SetSymbol(string symbol);
  bool SetAmountEquivalentTo1Dollar(double amount);

  // Getters for unit properties
  string GetName() const { return _unit_name; }
  string GetSymbol() const { return _unit_symbol; }
  double GetAmountEquivalentTo1Dollar() const { return _unit_amount; }

  // Equality comparison
  bool operator==(const MonetaryUnit& other) const;

 private:
  string _unit_name;  // Currency name
  string _unit_symbol;  // Currency symbol
  double _unit_amount;  // Value relative to 1 USD
};

#endif  // _MONETARYUNIT_H_

