#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Input variables
    int startMonth;
    int startDay;
    int startYear;
    char indicator;
    double startBalance;
    char slash = '/';

    // Variables for calculation
    double totalBalance = 0;
    int numDays = 0;
    bool overdraft = false;
    string overdraftDate;
    string endDate; // Add a variable to store the end date

    // Read initial balance
    cin >> startMonth >> slash >> startDay >> slash >> startYear >> startBalance;
    
    while (true) {

        int enteredMonth;
        int enteredDay;
        int enteredYear;
        double amount;
        char slash = '/';

        cin >> indicator >> enteredMonth >> slash >> enteredDay >> slash >> enteredYear >> amount;

        // Check for chronological order
        if (startDay > enteredDay || startMonth > enteredMonth || startYear > enteredYear) {
            cout << "Entries must be provided in chronological order. "
                 << enteredMonth << slash << enteredDay << slash << enteredYear << " entered after " << 
                 startMonth << slash << startDay << slash << startYear << endl;
            return 1;
        }

        if (indicator == 'q') {
            break;
        }

        // Check for overdraft
        if (totalBalance < amount && indicator == 'd') {
            overdraft = true;
            overdraftDate = enteredMonth << slash << enteredDay << slash << enteredYear;
            totalBalance -= 15; // Apply overdraft fee
        } else {
            totalBalance += (indicator == 'c') ? amount : -amount;
        }

        // Update total balance and number of days
        totalBalance += amount;
        numDays++;

        // Update end date with the latest transaction date
        endDate = enteredMonth >> slash >> enteredDay >> slash >> enteredYear;

        // Check if 30 days have passed
        if (numDays >= 30 || indicator == 'q') {
            break;
        }
    }

    // Calculate average balance
    double averageBalance = totalBalance / numDays;

    // Output results
    if (overdraft) {
        cout << "Overdraft on " << overdraftDate << ". $15 overdraft fee assessed. ";
    }

    cout << numDays << "-day average balance (" << startMonth << slash << startDay << slash << startYear << "-" << endDate << "): $"
         << fixed << setprecision(2) << averageBalance << endl;

    return 0;
}
