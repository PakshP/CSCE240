// Copyright 2024 Paksh Patel

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main() {
    // Declare variables for initial account information
    int startMonth, startDay, startYear;
    double startBalance, currentBalance, avgBalance = 0, total = 0;
    char indicator, slash, currIndicator;
    int currentMonth, currentDay, currentYear, currentTotal;
    double amount;

    // Define an array to store the number of days in each month
    const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Read initial account information from user input
    cin >> startMonth >> slash >> startDay >>
    slash >> startYear >> startBalance;

    // Initialize variables with initial values
    currentMonth = startMonth;
    currentDay = startDay;
    currentYear = startYear;
    currentTotal = 0;
    currentBalance = startBalance;

    // Declare variables for processing input data
    int month, day, year;
    int count = 0, totalDays = 0;

    // Start an infinite loop for processing transactions
    while (true) {
        // Read the transaction indicator ('d', 'c', or 'q')
        cin >> indicator;

        // Check if the indicator is 'q' to quit the loop
        if (indicator == 'q') {
            if (currIndicator == 'd')
                total += (currentBalance);
            else if (currIndicator == 'c')
                total += (currentBalance);
            break;
        }

        // Read the transaction date and amount
        cin >> month >> slash >> day >> slash >> year >> amount;

        // Check if the current year is a leap year
        bool leapYear = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

        // Calculate the total days for the current month
        if (month == startMonth) {
            totalDays = day - startDay + 1;
        } else if (month == startMonth + 1 ||
        (startMonth == 12 && month == 1)) {
            if (leapYear && startMonth == 2) {
                totalDays = ((29 - startDay) + day + 1);
             } else {
                totalDays = daysPerMonth[startMonth - 1] - startDay + day + 1;
            }
        } else if (month == startMonth + 2) {
            if (currentTotal <= 30) {
                totalDays = ((daysPerMonth[startMonth - 1] - startDay)
                + daysPerMonth[startMonth] + day + 1);
            } else {
                total = startBalance * 30;
                break;
            }
        } else {
            break;
        }
        // Calculate the total balance based on the transaction type
        if (totalDays > 30) {
            total += (currentBalance * (31 - currentTotal));
            break;
        }

        if (count == 0) {
            total = currentBalance * (totalDays - 1);
        } else {
            total += currentBalance * (totalDays - currentTotal);
        }

        // Check for chronological order of transactions
        if ((month < currentMonth && year < currentYear) ||
        (day < currentDay && month == currentMonth) || year < currentYear) {
            cout << "Entries must be provided in chronological order." << endl;
            cout << month << slash << day << slash << year <<
            " entered after " << currentMonth << slash << currentDay
                 << slash << currentYear << endl;
            break;
        }

        // Update current transaction details
        switch (indicator) {
        case 'd':
            currentBalance -= amount;
            if (currentBalance < 0) {
                currentBalance -= 15;
                cout << "Overdraft on " << month << slash << day <<
                slash << year << ". $15 overdraft fee assessed." << endl;
            }
            break;
        case 'c':
            currentBalance += amount;
            break;
        }

        currentMonth = month;
        currentDay = day;
        currentYear = year;
        currentTotal = totalDays;
        currIndicator = indicator;
        count++;
    }

    // Calculate and display the average balance
    if (indicator == 'q') {
        avgBalance = total / totalDays;

        cout << totalDays << "-day average balance (" <<
        startMonth << slash << startDay << slash << startYear << "-"
             << month << slash << day << slash << year << "): $" <<
             std::fixed << std::setprecision(2) << avgBalance << endl;
    }

    // Calculate and display the 30-day average balance if applicable
    if (totalDays > 30) {
        avgBalance = total / 30;

        if (currentMonth == startMonth && currentYear == startYear) {
            cout << "30-day average balance (" << startMonth <<
             slash << startDay << slash << startYear << "-"
                 << month << slash << (startDay + 29) << slash
                  << year << "): $" << std::fixed << std::setprecision(2)
                 << avgBalance << endl;
        } else if (currentMonth == startMonth + 1 && currentYear == startYear) {
            int new_day;
            if ((year % 400 == 0 || (year % 4 == 0
            && year % 100 != 0)) && startMonth == 2)
                new_day = 30 - (30 - startDay);
            else
                new_day = 30 - ((daysPerMonth[startMonth - 1] + 1) - startDay);
            cout << "30-day average balance (" << startMonth << slash
                 << startDay << slash << startYear << "-" << currentMonth
                 << slash << new_day << slash << currentYear << "): $"
                 << std::fixed << std::setprecision(2) << avgBalance << endl;
        }
    }
    return 0;
}
