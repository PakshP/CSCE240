// Copyright 2024 Paksh Patel
#include "program2functions.h"
#include <iostream>
#include <cmath>

bool IsPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

int NextPrime(int start) {
    for (int i = start + 1; ; ++i) {
        if (IsPrime(i)) return i;
    }
}

int PreviousPrime(int start) {
    for (int i = start - 1; i > 1; --i) {
        if (IsPrime(i)) return i;
    }
    return 2;
}

// Implementation of ToClosestPrime function
int ToClosestPrime(int num) {
    if (IsPrime(num)) return 0;

    int nextPrime = NextPrime(num);
    int prevPrime = PreviousPrime(num);

    if (num - prevPrime <= nextPrime - num) return prevPrime - num;
    return nextPrime - num;
}

// Implementation of PrintPrimesBetween function
void PrintPrimesBetween(int lower, int upper, bool inclusive) {
    bool firstPrint = true;
    for (int i = lower; i <= upper; ++i) {
        if (IsPrime(i) && (inclusive || (i != lower && i != upper))) {
            if (!firstPrint) std::cout << ", ";
            std::cout << i;
            firstPrint = false;
        }
    }
    std::cout << std::endl;
}

// Implementation of LargestPrimeSequence function
int LargestPrimeSequence(int num) {
    #include <string>

    std::string numStr = std::to_string(num);
    int maxLength = numStr.length();
    int largestPrime = -1;

    for (int length = 1; length <= maxLength; ++length) {
        for (int start = 0; start <= maxLength - length; ++start) {
            int val = std::stoi(numStr.substr(start, length));
            if (IsPrime(val) && val > largestPrime) {
                largestPrime = val;
            }
        }
    }

    return largestPrime;
}

// Implementation of PrintAsDollarsAndCents function
void PrintAsDollarsAndCents(int amount) {
    int dollars = amount / 100;
    int cents = amount % 100;
    printf("$%d.%02d\n", dollars, cents);
}

// Implementation of MakePurchase function
bool MakePurchase(int cost, int &twentyDollarBills, int &tenDollarBills,
                  int &fiveDollarBills, int &oneDollarBills, int &quarters,
                  int &dimes, int &nickels, int &pennies) {
    // Convert all amounts to cents for easier calculations
    int total = twentyDollarBills * 2000 + tenDollarBills * 1000 +
                fiveDollarBills * 500 + oneDollarBills * 100 + quarters * 25 +
                dimes * 10 + nickels * 5 + pennies;
    if (cost > total) return false;

    int change = total - cost;
    twentyDollarBills = change / 2000;
    change %= 2000;
    tenDollarBills = change / 1000;
    change %= 1000;
    fiveDollarBills = change / 500;
    change %= 500;
    oneDollarBills = change / 100;
    change %= 100;
    quarters = change / 25;
    change %= 25;
    dimes = change / 10;
    change %= 10;
    nickels = change / 5;
    change %= 5;
    pennies = change;

    return true;
}
