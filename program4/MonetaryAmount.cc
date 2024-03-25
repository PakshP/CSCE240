// Copyright 2024 Paksh Patel
#include<iostream>

using std::ostream;

#include "MonetaryAmount.h"

// Initialize static data members
bool MonetaryAmount::display_unit_name = false;

// definition and implementation of Constructor
MonetaryAmount::MonetaryAmount(double value, const MonetaryUnit& object) :
    _value(value), _object(object) {
}

// definition and implementation of ConvertToUnit
void MonetaryAmount::ConvertToUnit(const MonetaryUnit& object) {
  // Convert the value to the given unit
  double conversion_factor = object.GetAmountEquivalentTo1Dollar()
  / _object.GetAmountEquivalentTo1Dollar();
  _value *= conversion_factor;
  _object = object;
}

bool MonetaryAmount::operator==(const MonetaryAmount& anObject) const {
  double object_value = anObject._value;
  // Check if the values are equal
  if (!(_object == anObject._object)) {
    // Convert the value to the given unit
    object_value *=  _object.GetAmountEquivalentTo1Dollar()
    / anObject._object.GetAmountEquivalentTo1Dollar();
  }
  return _value == object_value;  // Return boolean value
}

// definition and implementation of overloaded operators
bool MonetaryAmount::operator<(const MonetaryAmount& anObject) const {
  double object_value = anObject._value;
  if (!(_object == anObject._object)) {
    object_value *= _object.GetAmountEquivalentTo1Dollar()
    / anObject._object.GetAmountEquivalentTo1Dollar();
  }
  return _value < object_value;
}

bool MonetaryAmount::operator>(const MonetaryAmount& anObject) const {
  double object_value = anObject._value;
  if (!(_object == anObject._object)) {
    object_value *= _object.GetAmountEquivalentTo1Dollar()
    / anObject._object.GetAmountEquivalentTo1Dollar();
  }
  return _value > object_value;
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
  double object_value = mu_one.GetValue();
  // Check if the units are different
  if (!(mu_one.GetUnit() == mu_two.GetUnit())) {
    // Convert the value to the given unit
    double conversion_factor = mu_one.GetUnit().GetAmountEquivalentTo1Dollar()
    / mu_two.GetUnit().GetAmountEquivalentTo1Dollar();
    double new_value = mu_two.GetValue() * conversion_factor;
    object_value += new_value;
  } else {  // If the units are same
    object_value += mu_two.GetValue();
  }
  // Return the new MonetaryAmount object
  return MonetaryAmount(object_value, mu_one.GetUnit());
}
