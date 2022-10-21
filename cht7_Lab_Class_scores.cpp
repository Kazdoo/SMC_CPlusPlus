//by Olivier Ged
//10/20/2022
//cs52 Santa monica College




#include <iostream>
#include <fstream>
using namespace std;

void classAverage(ifstream& in, double& average);

int main() {

    double average = 0;
    int score;
    int n = 1;
    double grade;

    ifstream fin;
    fin.open("students_score.txt");
    if (fin.fail()) {
        cout << "int file opening failed.\n";
    }

    classAverage(fin, average);
    cout << "average:" << average << endl;
    fin.close();

    fin.open("students_score.txt");

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);
    while (fin >> score) {
        cout << "student " << n << ": score:" << score;
        n++;
        grade = score * 100 / average;
        if (grade > average)
            grade = 100;
        cout << ", grade:" << grade << "%" << endl;
    }
return 0;
}

    void classAverage(ifstream& in, double& average)
    {
        int score;
        int count;
        double sum;

        while (in >> score)
        {
            count++;
            sum = sum + score;
        }
        average = sum/count;
    }