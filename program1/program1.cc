#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{

    int startMonth, startDay, startYear;
    double startBalance, currentBalance, avgBalance = 0, total = 0;
    char indicator, slash, currIndicator;
    int currentMonth, currentDay, currentYear, currentTotal;
    double amount;

    const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    cin >> startMonth >> slash >> startDay >> slash >> startYear >> startBalance;

    currentMonth = startMonth;
    currentDay = startDay;
    currentYear = startYear;
    currentTotal = 0;
    currentBalance = startBalance;

    int month, day, year;
    int count = 0, totalDays = 0;
    while (true)
    {
        cin >> indicator;

        if (indicator == 'q')
        {
            if (currIndicator == 'd')
                total += (currentBalance);
            else if (currIndicator == 'c')
                total += (currentBalance);
            break;
        }

        cin >> month >> slash >> day >> slash >> year >> amount;

        // Finds if it is leap year and what the total days are;
        bool leapYear = (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));

        if (month == startMonth)
        {
            totalDays = day - startDay + 1;
        }
        else if (month == startMonth + 1 || (startMonth == 12 && month == 1))
        {
            if (leapYear && startMonth == 2)
                totalDays = ((29 - startDay) + day + 1);
            else
            {
                totalDays = daysPerMonth[startMonth - 1] - startDay + day + 1;
            }
        }
        else if (month == startMonth + 2)
        {
            if (currentTotal <= 30)
                totalDays = ((daysPerMonth[startMonth - 1] - startDay) + daysPerMonth[startMonth] + day + 1);
            else
            {
                total = startBalance * 30;
                break;
            }
        }
        else
            break;

        if (totalDays > 30)
        {
            total += (currentBalance * (31 - currentTotal));
            break;
        }

        if (count == 0)
        {
            total = currentBalance * (totalDays - 1);
        }
        else
        {
            total += currentBalance * (totalDays - currentTotal);
        }

        // Works
        if ((month < currentMonth && year < currentYear) || (day < currentDay && month == currentMonth) || year < currentYear)
        {
            cout << "Entries must be provided in chronological order." << endl;
            cout << month << slash << day << slash << year << " entered after " << currentMonth << slash << currentDay
                 << slash << currentYear << endl;
            break;
        }

        // Credit and debit
        switch (indicator)
        {
        case 'd':
            currentBalance -= amount;
            if (currentBalance < 0)
            {
                currentBalance -= 15;
                cout << "Overdraft on " << month << slash << day << slash << year << ". $15 overdraft fee assessed." << endl;
            }
            break;
        case 'c':
            currentBalance += amount;
            break;
        }

        // cout << total << endl;
        currentMonth = month;
        currentDay = day;
        currentYear = year;
        currentTotal = totalDays;
        currIndicator = indicator;
        count++;
    }

    if (indicator == 'q')
    {
        avgBalance = total / totalDays;
        // cout << totalDays << endl;
        // cout << total << endl;
        cout << totalDays << "-day average balance (" << startMonth << slash << startDay << slash << startYear << "-"
             << month << slash << day << slash << year << "): $" << std::fixed << std::setprecision(2) << avgBalance << endl;
    }

    // Fix
    if (totalDays > 30)
    {
        avgBalance = total / 30;

        if (currentMonth == startMonth && currentYear == startYear)
        {
            cout << "30-day average balance (" << startMonth << slash << startDay << slash << startYear << "-"
                 << month << slash << (startDay + 29) << slash << year << "): $" << std::fixed << std::setprecision(2)
                 << avgBalance << endl;
        }
        else if (currentMonth == startMonth + 1 && currentYear == startYear)
        {
            int new_day;
            if ((year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) && startMonth == 2)
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