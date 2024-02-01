// Copyright 2024 Paksh Patel
#ifndef PROGRAM2_PROGRAM2FUNCTIONS_H_
#define PROGRAM2_PROGRAM2FUNCTIONS_H_

// Function prototypes
int ToClosestPrime(int num);
void PrintPrimesBetween(int lower, int upper, bool inclusive = false);
int LargestPrimeSequence(int num);
void PrintAsDollarsAndCents(int amount);
bool MakePurchase(int cost, int *twentyDollarBills, int *tenDollarBills,
                  int *fiveDollarBills, int *oneDollarBills, int *quarters,
                  int *dimes, int *nickels, int *pennies);

#endif  // PROGRAM2_PROGRAM2FUNCTIONS_H_
