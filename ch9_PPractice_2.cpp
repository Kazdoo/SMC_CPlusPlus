#include <iostream>

typedef double* Doubleptr;

int main() {

    int numDoubles; //well...not using this, I changed a bit what the PPractice wanted us to do.

    Doubleptr p;
    p = new double [5];
    double sum;
    double average;


    std::cout << "Please enter 5 integer:" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        std::cin >> p[i];
        sum = sum + p[i];
    }
        average = sum/5;

    delete [] p;

    std::cout<< average<< std::endl;

    return 0;
}
