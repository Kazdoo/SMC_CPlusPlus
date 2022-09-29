//File Name: Mod1_prog_project_#2.cpp
//author: Olivier Ged
//SMC CS52 Fall 2022
//Last change: 09/28/2022

/*

Write a C++ program that solves a quadratic equation to find its roots.
The roots of a quadratic equation
ax2 + bx + c = 0
(where a is not zero) are given by the formula
(−b ± sqrt(b2 − 4ac)) / 2a

The program takes values of a, b, and c as input and outputs the roots. Be
creative in how you output complex roots. Include a loop that allows the
user to repeat this calculation for new input values until the user says she
or he wants to end the program.

 Note: I had to go search for some help on this one as quadratic equations are not super fresh in my memory.
 The logic is from me.

 */
#include <iostream>
#include <cmath> //for the square root
using namespace std;


int main()
{
    char one_more;
    int a, b, c;
    double discriminant, root_1, root_2, imaginaryRoot;

    do {
    cout <<"input 3 values (a, b anc d) to find the roots of the quadratic expression\na:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c:";
    cin >> c;

    discriminant = b*b - (4*a*c);
    cout << discriminant << endl;

    if (discriminant == 0)
    {
        root_1 = root_2 = -b / (2*a);
        cout << "roots are identical, R1 & R2:" << root_1 <<endl;
    }
    else if(discriminant >0)
    {
        root_1 = (-b + sqrt(discriminant))/ (2*a);
        root_2 = (-b - sqrt(discriminant))/ (2*a);
        cout << "there is 2 real roots, R1:" << root_1 << " and R2:" << root_2 <<endl;
    }
    else
    {
        root_1 = -b/(2*a);
        imaginaryRoot =sqrt(-discriminant)/(2*a);
        cout << "Roots are complex and different, R1=" << root_1 << "+" << imaginaryRoot << "i" <<endl;
        cout << "Roots are complex and different, R2=" << root_1 << "-" << imaginaryRoot << "i" <<endl;
    }
    cout << "another go at it? (y/n)";
    cin >> one_more;
    }
    while (one_more == 'y' || one_more == 'Y');
    return 0;
}
