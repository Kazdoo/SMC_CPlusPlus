//File Name: Mod1_prog_project_#3.cpp
//author: Olivier Ged
//SMC CS52 Fall 2022
//Last change: 09/28/2022

/*

Write a program that accepts a year written as a four-digit Arabic (ordinary)
numeral and outputs the year written in Roman numerals.

Important Roman numerals are V for 5, X for 10, L for 50, C for 100, D for 500, and
M for 1,000. Recall that some numbers are formed by using a kind of
subtraction of one Roman “digit”; for example, IV is 4 produced as V minus
I, XL is 40, CM is 900, and so on. A few sample years: MCM is 1900, MCML
is 1950, MCMLX is 1960, MCMXL is 1940, MCMLXXXIX is 1989.

Assume the year is between 1000 and 3000. Your program should include a loop
that lets the user repeat this calculation until the user says she or he is done
 */

#include <iostream>
using namespace std;

int main()
{
    char one_more;
    int number,M,H,T,U;



    do {
        cout << "Enter a number between 1000 and 3999:";
        cin >> number;

        U = number %10;
        T = number /10 %10;
        H = number /100 %10;
        M = number /1000 %10;

        //print Thousands
        for (int i = 0; i < M ; i++)
            cout << 'M';
        
        //print Hundreds
        if (H < 4){
            for (int i = 0; i < H ; i++)
                cout << 'C';
        }
        else if (H == 4)
            cout << "CD";

        else if (H == 5)
            cout << 'D';

        else if (H == 9)
            cout << "CM";

        else if (H > 5){
            cout << 'D';
            for (int i = 0; i < H-5 ; i++)
                cout << 'C';
        }
        
        //print Tens
        if (T < 4){
            for (int i = 0; i < T ; i++)
                cout << 'X';
        }
        else if (T == 4)
            cout << "XL";

        else if (T == 5)
            cout << 'L';

        else if (T == 9)
            cout << "XC";

        else if (T > 5){
            cout << 'L';
            for (int i = 0; i < T-5 ; i++)
                cout << 'X';
        }

        //print Units
        if (U < 4){
            for (int i = 0; i < U ; i++)
                cout << 'I';
        }
        else if (U == 4)
            cout << "IV";

        else if (U == 5)
            cout << 'V';

        else if (U == 9)
            cout << "IX";

        else if (T > 5){
            cout << 'V';
            for (int i = 0; i < T-5 ; i++)
                cout << 'I';
        }
    cout << endl;
    cout <<"another go at it? (y/n)";
    cin >> one_more;
    }

    while (one_more == 'y' || one_more == 'Y');
    return 0;
}
