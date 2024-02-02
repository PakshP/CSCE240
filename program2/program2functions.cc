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
    if (IsPrime(num))
        return 0;

    int nextPrime = NextPrime(num);
    int prevPrime = PreviousPrime(num);

    int distToNext = abs(nextPrime - num);
    int distToPrev = abs(num - prevPrime);

    if (distToNext > distToPrev) {
        return prevPrime - num;
    } else {
        return nextPrime - num;
    }
}

// Implementation of PrintPrimesBetween function
void PrintPrimesBetween(int lower, int upper, bool inclusive) {
    bool firstPrint = true;
    int start = inclusive ? lower : lower + 1;
    for (int i = start; i <= (inclusive ? upper : upper - 1); ++i) {
        if (IsPrime(i)) {
            if (!firstPrint) {
                std::cout << ", ";
            }
            std::cout << i;
            firstPrint = false;
        }
    }
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
    printf("$%d.%02d", dollars, cents);
}

// Implementation of MakePurchase function
bool MakePurchase(int cost, int& twentyDollarBills, int& tenDollarBills,
                  int& fiveDollarBills, int& oneDollarBills, int& quarters,
                  int& dimes, int& nickels, int& pennies) {
  int total_money = twentyDollarBills * 2000 + tenDollarBills * 1000 +
  fiveDollarBills * 500 + oneDollarBills * 100 + quarters * 25 + dimes * 10 +
  nickels * 5 + pennies;

  if (total_money < cost) {
    return false;
  }

  while (abs(2000 - cost) < abs(1000 - cost) &&
         twentyDollarBills > 0 && cost > 0) {
    twentyDollarBills--;
    cost -= 2000;
  }
  while (abs(1000 - cost) < abs(500 - cost) &&
         tenDollarBills > 0 && cost > 0) {
    tenDollarBills--;
    cost -= 1000;
  }
  while (abs(500 - cost) < abs(100 - cost) &&
         fiveDollarBills > 0 && cost > 0) {
    fiveDollarBills--;
    cost -= 500;
  }
  while (abs(100 - cost) < abs(25 - cost) &&
         oneDollarBills > 0 && cost > 0) {
    oneDollarBills--;
    cost -= 100;
  }
  while (abs(25 - cost) < abs(10 - cost) &&
         quarters > 0 && cost > 0) {
    quarters--;
    cost -= 25;
  }
  while (abs(10 - cost) < abs(5 - cost) &&
         dimes > 0 && cost > 0) {
    dimes--;
    cost -= 10;
  }
  while (abs(5 - cost) > 1 &&
         nickels > 0 && cost > 0) {
    nickels--;
    cost -= 5;
  }
  while (abs(1 - cost) < 0 &&
         pennies > 0 && cost > 0) {
    pennies--;
    cost--;
  }
  if (cost < 0) {
    int change = -1 * cost;
    while (abs(2000 - change) <= abs(1000 - change) &&
           change - 2000 >= 0) {
      twentyDollarBills++;
      change -= 2000;
    }
    while (abs(1000 - change) <= abs(500 - change) &&
               change - 1000 >= 0) {
      tenDollarBills++;
      change -= 1000;
    }
    while (abs(500 - change) <= abs(100 - change) &&
           change - 500 >= 0) {
      fiveDollarBills++;
      change -= 500;
    }
    while (abs(100 - change) <= abs(25 - change) &&
           change - 100 >= 0) {
      oneDollarBills++;
      change -= 100;
    }
    while (abs(25 - change) < abs(10 - change) &&
           change - 25 >= 0) {
      quarters++;
      change -= 25;
    }
    while (abs(10 - change) < abs(5 - change) &&
           change - 10 >= 0) {
      dimes++;
      change -= 10;
    }
    while (abs(5 - change) < abs(1 - change) &&
           change - 5 >= 0) {
      nickels++;
      change -= 5;
    }
    while (change - 1 >= 0) {
      pennies++;
      change--;
    }
  }
  return true;
}
