// Copyright 2024 Paksh Patel
#include<iostream>

using std::ostream;

#include "MonetaryAmount.h"

// Initialize static data members
bool MonetaryAmount::display_unit_name = false;

// definition and implementation of Constructor
MonetaryAmount::MonetaryAmount(double value, const MonetaryUnit& unit) :
    _value(value), _unit(unit) {
}

// definition and implementation of ConvertToUnit
void MonetaryAmount::ConvertToUnit(const MonetaryUnit& unit) {
  // Convert the value to the given unit
  double conversion_factor = unit.GetAmountEquivalentTo1Dollar()
  / _unit.GetAmountEquivalentTo1Dollar();
  _value *= conversion_factor;
  _unit = unit;
}

bool MonetaryAmount::operator==(const MonetaryAmount& anunit) const {
  double unit_value = anunit._value;
  // Check if the values are equal
  if (!(_unit == anunit._unit)) {
    // Convert the value to the given unit
    unit_value *=  _unit.GetAmountEquivalentTo1Dollar()
    / anunit._unit.GetAmountEquivalentTo1Dollar();
  }
  return _value == unit_value;  // Return boolean value
}

// definition and implementation of overloaded operators
bool MonetaryAmount::operator<(const MonetaryAmount& anunit) const {
  double unit_value = anunit._value;
  if (!(_unit == anunit._unit)) {
    unit_value *= _unit.GetAmountEquivalentTo1Dollar()
    / anunit._unit.GetAmountEquivalentTo1Dollar();
  }
  return _value < unit_value;
}

bool MonetaryAmount::operator>(const MonetaryAmount& anunit) const {
  double unit_value = anunit._value;
  if (!(_unit == anunit._unit)) {
    unit_value *= _unit.GetAmountEquivalentTo1Dollar()
    / anunit._unit.GetAmountEquivalentTo1Dollar();
  }
  return _value > unit_value;
}

ostream& operator<<(ostream& os, const MonetaryAmount& mu) {
  /*
  Display different output based on the static data member
  if display_unit_name is true, display the unit name
  else display the unit symbol
  */
  if (MonetaryAmount::display_unit_name) {
    os << mu.GetValue() << " " << mu.GetUnit().GetName();
  } else {
    os << mu.GetUnit().GetSymbol() << mu.GetValue();
  }
  return os;
}

MonetaryAmount operator+(const MonetaryAmount& mu_one,
const MonetaryAmount& mu_two) {
  double unit_value = mu_one.GetValue();
  // Check if the units are different
  if (!(mu_one.GetUnit() == mu_two.GetUnit())) {
    // Convert the value to the given unit
    double conversion_factor = mu_one.GetUnit().GetAmountEquivalentTo1Dollar()
    / mu_two.GetUnit().GetAmountEquivalentTo1Dollar();
    double new_value = mu_two.GetValue() * conversion_factor;
    unit_value += new_value;
  } else {  // If the units are same
    unit_value += mu_two.GetValue();
  }
  // Return the new MonetaryAmount unit
  return MonetaryAmount(unit_value, mu_one.GetUnit());
}
