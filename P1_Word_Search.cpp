//by Olivier Ged
//SMC CS52
//10/24/2022


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void menu();
void inputForPuzzle();
void generatePuzzle();
void savePuzzle(std::string); //will pass the puzzle once we have figured it out.
void openPuzzle();
void openFile(std::ifstream& file);
void displayPuzzle(std::ifstream& file);
void solvePuzzle();

int main() {

    menu();

    return 0;
}

void menu()
{
    int choice;

    std::cout<<"(1) Create a new Puzzle\n"
            << "(2) Open an existing Puzzle\n"
            << "(3) Solve an existing Puzzle\n"
            << "(4) Exit\n";

    std::cin >> choice;

    switch (choice){
        case 1: generatePuzzle(); break;
        case 2: openPuzzle();break;
        case 3: solvePuzzle();break;
        case 4: std::cout<<"bye!"; return;

    }
        }

void inputForPuzzle()
{
    int numberOfWords;
    std::vector <std::string> v;
    std::string next;

    std::cout<<"how many words in your puzzle?"<<std::endl;
    std::cin >> numberOfWords;

    std::cout<<"Enter the words for your puzzle:" <<std::endl;

    for (int i = 0; i<numberOfWords; i++)
    {
        std::cin >> next;
        v.push_back(next);
        std::cout << v[i]<<std::endl;
    }

}

void generatePuzzle()
{
    //very temp until we find out the puzzle generation part.
    std::string (temp) ="asdasada"
                 "sadadasdas"
                 "fdgdfgdf";

    char ans;

    inputForPuzzle();
    // some function to generate a puzzle

    std::cout<<"do you want to save this Puzzle?\n";
    if (ans == 'y' || ans =='Y')
        savePuzzle(temp);
    else
        menu();


}

void openPuzzle()
{
    std::ifstream file;

    openFile(file);
    displayPuzzle(file);

    file.close();
    menu();

}

void displayPuzzle(std::ifstream& file)
{
    char ch;
    while(file)
    {
        ch=file.get();
        std::cout<< ch ;
    }
    std::cout<<std::endl<<std::endl;
}

void openFile(std::ifstream& file)
{
    std::string name;

    std::cout<<"enter the name of file you want to open:\n";
    std::cin >> name;

    file.open(name);
    if (file.fail())
    {
        std::cout<<"file: " <<name<<" failed to open.\n";
    }

}

void solvePuzzle()
{

        std::ifstream file;
        openFile(file);

        //some function to solve the puzzle and display it.

        file.close();
        menu();
}

void savePuzzle(std::string s)
{
    std::string name;
    std::ofstream file;

    std::cout<<"name the file for saving the puzzle: \n";
    std::cin >> name;

    file.open (name);

    file << s;

    file.close();
    menu();

}