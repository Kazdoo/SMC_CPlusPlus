// by Olivier Ged
//SMC Cs52 Fall 2022
//10/26/2022

#include <iostream>

void addOne ( int *ptrNum);



int main() {

    int a = 8;
    int *p;

    p = &a;

    addOne(p);

    std::cout<< a << std::endl;


    return 0;
}

void addOne (int *ptrNum)
{

    *ptrNum +=1;


}