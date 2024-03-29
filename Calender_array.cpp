#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

bool isleapyear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calculate(int month, int year)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else if (month == 2)
    {
        return isleapyear(year) ? 29 : 28;
    }
    else
    {
        return 31;
    }
}

void calender(int day, int month, int year)
{
    vector<vector<int>> calendar(6, vector<int>(7, 0)); // 6 rows, 7 columns

    tm timeinfo = {0, 0, 0, 1, month - 1, year - 1900};
    time_t rawtime = mktime(&timeinfo);
    struct tm *timeinfoStruct = localtime(&rawtime);
    int startingDay = timeinfoStruct->tm_wday;

    int row = 0;
    cout << "|---------------------------|" << endl;
    cout << "|sun|mon|tue|wed|thu|fri|sat|" << endl;
    cout << "|---------------------------|" << endl;
    for (int dayNum = 1; dayNum <= calculate(month, year); dayNum++)
    {
        calendar[row][startingDay] = dayNum;
        //cout << startingDay << endl;
        startingDay = (startingDay + 1) % 7;
        //cout << startingDay << endl;

        if (startingDay == 0)
        {
            if (row < 4)
            {
                row++;
            }
            else
            {
                row = 0;
            }
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (calendar[i][j] == day)
            {
                cout << "\033[1;47m" << setw(3) << calendar[i][j] << "\033[0m ";
            }
            else if (calendar[i][j] != 0)
            {
                cout << setw(3) << calendar[i][j] << " ";
            }
            else
            {
                cout << "  - ";
            }
        }
        cout << endl;
    }
    cout << "|---------------------------|" << endl;
}

int main()
{
    cout << "Enter Months Amount: ";
    int n;
    cin >> n;
    int day,month,year;
    for (int i = 0; i < n; i++)
    {
        cout <<"Input Date (dd/mm/yyyy): ";
        scanf("%d/%d/%d", &day, &month, &year);
        calender(day, month, year);
    }
    return 0;
}