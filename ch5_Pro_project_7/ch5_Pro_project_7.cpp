#include <iostream>

// return true is a leap year.
bool isLeapYear(int year);

//
int getCenturyValue (int year);

//
int getYearValue (int gear);

//
int getMonthValue (int month, int year);

//return the day of the year based on weird calculation made by wikipedia :D
void dayOfTheYear(int day, int month, int year);

//capturing user's input
void getInput(int&day, int&month, int&year);


int main()

{

    int day;
    int month;
    int year;

    getInput(day, month, year);
    dayOfTheYear(day, month, year);

    return 0;
}


bool isLeapYear(int year)
{
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
        return true;
    } else
        return false;

}

int getCenturyValue (int year)
{
    int century, centuryValue, remainder;

    century = year/100;
    remainder= century%4;
    centuryValue = (3- remainder)*2;

    return centuryValue;

}

int getYearValue(int year)
{
    int yearValue;
    yearValue= (year%100 / 4) + year%100;
}

int getMonthValue (int month, int year)
{
        int monthValue = 0;


        switch(month){
            case 1:

                if(isLeapYear(year))
                {
                    monthValue = 6;
                }

                else
                    monthValue = 0;

                break;


            case 2:

                if(isLeapYear(year))
                {
                    monthValue=2;
                }
                else
                    return 3;
                break;

            case 3:monthValue = 3;break;
            case 4:monthValue = 6;break;
            case 5:monthValue = 1;break;
            case 6:monthValue = 4;break;
            case 7:monthValue = 6;break;
            case 8:monthValue = 2;break;
            case 9:monthValue = 5;break;
            case 10:monthValue = 0;break;
            case 11:monthValue = 3;break;
            case 12:monthValue = 5;break;
        }

        return monthValue;


}

void dayOfTheYear(int day, int month, int year)
{
    int day_indicator;
    day_indicator=(day + getMonthValue(month, year)+ getYearValue(year) + getCenturyValue(year)) % 7;

    switch (day_indicator) {
        case 0: std::cout<<"sunday";break;
        case 1: std::cout<<"monday";break;
        case 2: std::cout<<"tuesday";break;
        case 3: std::cout<<"wednesday";break;
        case 4: std::cout<<"thursday";break;
        case 5: std::cout<<"friday";break;
        case 6: std::cout<<"saturday";break;

    }


}

void getInput(int&day, int&month, int&year)
{
    char slash;
    std::cout<<"enter a date mm/dd/yyyy"<<std::endl;
    std::cin >> month >> slash>> day >>slash>> year;

}

