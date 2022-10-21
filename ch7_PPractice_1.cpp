//by Olivier Ged
//10/20/2022
//cs52 Santa monica College

#include <iostream>


double findMax (double arr [], int size);



int main() {
    double a []={2, 4, 5, 6, 7};
    double b []={-4.2, 3, 11, 204.5, 4.3,-203};
    double c [5];

    std::cout << findMax(a, 5)<<std::endl;
    std::cout<< findMax(b, 6) <<std::endl;
    std::cout << findMax(c,5) <<std::endl;


    return 0;
}


double findMax (double arr [], int size)
{

    double largest;

    largest = arr[0];
    for (int index =0; index < size; index++)
        if (largest<arr[index])

            largest = arr[index];

    return largest;



}