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

    int count = 1;
    tm timeinfo = {0, 0, 0, 1, month - 1, year - 1900};
    time_t rawtime = mktime(&timeinfo);
    struct tm *timeinfoStruct = localtime(&rawtime);
    int startingDay = timeinfoStruct->tm_wday;

    for (int i = 0; i < startingDay; ++i)
    {
        calendar[0][i] = -1; // Mark unused cells as -1
    }

    int row = 0;
    for (int dayNum = 1; dayNum <= calculate(month, year); dayNum++)
    {
        if ((startingDay + dayNum) % 7 == 0)
        {
            count++;
        }

        calendar[row][dayNum - 1 + startingDay] = dayNum;

        if (count > 5)
        {
            count = 1;
            row++;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 7; ++j)
        {
            if (calendar[i][j] == -1)
            {
                cout << "   ";
            }
            else
            {
                if (calendar[i][j] == day)
                {
                    cout << "\033[1;47m" << setw(2) << calendar[i][j] << "\033[0m ";
                }
                else
                {
                    cout << setw(2) << calendar[i][j] << " ";
                }
            }
        }
        cout << endl;
    }
}

int main()
{
    int day, month, year;
    cout << "Input Date (dd/mm/yyyy): ";
    scanf("%d/%d/%d", &day, &month, &year);
    calender(day, month, year);
    return 0;
}