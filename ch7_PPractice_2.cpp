//by Olivier Ged
//10/20/2022
//cs52 Santa monica College
#include <iostream>


int sumAll  (int arr [], int size);



int main() {
    int a []={2, 4, 5, 6, 7};
    int b []={-4, 3, 11, 204, 4,-203};
    int c [5];

    std::cout << sumAll(a, 5)<<std::endl;
    std::cout<< sumAll(b, 6) <<std::endl;
    std::cout << sumAll(c,5) <<std::endl;


    return 0;
}


int sumAll  (int arr [], int size)
{

    int sum=0;

    for (int index =0; index < size; index++)
        sum += arr[index];
    return sum;



}