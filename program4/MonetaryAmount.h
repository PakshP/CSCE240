// Copyright 2024 Paksh Patel
#ifndef _MONETARY_AMOUNT_H_
#define _MONETARY_AMOUNT_H_
#include "MonetaryUnit.h"
#include <iostream>
using std::ostream;

class MonetaryAmount {
 public:
  // Initialize with default or specified value and unit
  explicit MonetaryAmount(double value = 0,
  const MonetaryUnit& unit = MonetaryUnit("US dollars", "$", 1));

  // Default destructor
  ~MonetaryAmount() {}

  // Accessors
  double GetValue() const { return _value; }
  MonetaryUnit GetUnit() const { return _unit; }

  // Convert to specified unit
  void ConvertToUnit(const MonetaryUnit& targetUnit);

  // Control display of unit names
  static bool display_unit_name;

  // Comparison operators
  bool operator==(const MonetaryAmount& other) const;
  bool operator<(const MonetaryAmount& other) const;
  bool operator>(const MonetaryAmount& other) const;

  // Stream and arithmetic operations
  friend ostream& operator<<(ostream& os, const MonetaryAmount& amount);
  friend MonetaryAmount operator+(const MonetaryAmount& lhs,
  const MonetaryAmount& rhs);

 private:
  double _value;  // Monetary value
  MonetaryUnit _unit;  // Associated currency unit
};

#endif  // _MONETARY_AMOUNT_H_
