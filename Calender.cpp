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
    int count = 0;
    tm timeinfo = {0, 0, 0, 1, month - 1, year - 1900};
    time_t rawtime = mktime(&timeinfo);
    struct tm* timeinfoStruct = localtime(&rawtime);
    int startingDay = timeinfoStruct->tm_wday;
    cout << startingDay << endl;
    for (int i = 0; i < startingDay; i++) 
    {
        cout << " - ";
    }
    for (int dayNum = 1; dayNum <= calculate(month, year); dayNum++) 
    {
        if (dayNum == day)
        {
            cout <<"\033[1;47m" << dayNum << "\033[0m" <<" ";
        }
        else
        {
            cout << setw(2) << dayNum << " ";
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
    int day,month,year;
    cout <<"Input Date (dd/mm/yyyy): ";
    scanf("%d/%d/%d", &day, &month, &year);
    calender(day, month, year);
    return 0;
}
