#include <iostream>
#include <iomanip>

using namespace std;

bool isleapyear(int year)
{
    return (year%4 == 0 && year%100 != 0) || (year%400 == 0);
}
int calculate(int month, int year)
{
    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        return 30;
    }
    else if (month == 2)
    {
        return isleapyear(year) ? 29:28;
    }
    else
    {
        return 31;
    }   
}
void calender (int day, int month, int year)
{
    int total, finish;
    int count = 0;
    tm timeinfo = {0, 0, 0, 1, month - 1, year - 1900};
    time_t rawtime = mktime(&timeinfo);
    struct tm* timeinfoStruct = localtime(&rawtime);
    int startingDay = timeinfoStruct->tm_wday;
    cout << "|---------------------------|" << endl;
    cout << "|sun|mon|tue|wed|thu|fri|sat|" << endl;
    cout << "|---------------------------|" << endl;
    //cout << startingDay << endl;
    total = calculate(month, year);
    finish = (28 + (7 - startingDay));
    if (finish > total)
    {
        finish = total;
    }
    //cout << finish << endl;

    for (int i = 1; i <= (total - finish); i++) 
    {
        cout <<" "<< finish + i << " ";
    }
    for (int i = 0; i < startingDay - (total - finish); i++) 
    {
        cout << "  - ";
    }
    for (int dayNum = 1; dayNum <= finish; dayNum++)
    {
        if (dayNum == day)
        {
            if (dayNum == 1 || dayNum == day)
            {
                cout << " ";
            }
            cout <<"\033[1;47m" << dayNum << "\033[0m" << " ";
        }
        else
        {
            cout << setw(3) << dayNum << " ";
        }
        
        if ((startingDay + dayNum)%7 == 0) 
        {
            count++;
            cout << endl;
        }
    }
    cout << endl;
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