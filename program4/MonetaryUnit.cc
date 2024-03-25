// Copyright 2024 Paksh Patel
#include<iostream>
using std::cout;
using std::endl;
using std::ostream;
#include<string>
using std::string;

#include "MonetaryUnity.h"

// Constructor
MonetaryUnit::MonetaryUnit(string name, string symbol, double amount) :
_unit_name("US dollars"), _unit_symbol("$"), _unit_amount(1) {
  SetName(name);
  SetSymbol(symbol);
  SetAmountEquivalentTo1Dollar(amount);
}

// Set name if not empty
bool MonetaryUnit::SetName(string name) {
  if (name.length() > 0) _unit_name = name;
  return _unit_name == name;
}

// Set symbol if not empty
bool MonetaryUnit::SetSymbol(string symbol) {
  if (symbol.length() > 0) _unit_symbol = symbol;
  return _unit_symbol == symbol;
}

// Set amount if positive
bool MonetaryUnit::SetAmountEquivalentTo1Dollar(double amount) {
  if (amount > 0) _unit_amount = amount;
  return _unit_amount == amount;
}

// Check equality
bool MonetaryUnit::operator==(const MonetaryUnit& obj) const {
  return (_unit_name == obj._unit_name &&
  _unit_symbol == obj._unit_symbol && _unit_amount == obj._unit_amount);
}
