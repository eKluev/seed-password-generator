#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateWithSeed()
{
    system("cls");
    static const char charsList[] =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "123456789"
        "*!@#%&?";

    hash<string> stringHash;
    string seed;
    int size;

    cout << "Enter password seed: ";
    cin >> seed;
    cout << "Enter password size: ";
    cin >> size;

    srand(stringHash(seed));
    string result;

    for (int i = 0; i < size; i++)
    {
        result += charsList[rand() % sizeof(charsList) - 1];
    }

    cout << "Your password: " << result;
   
    int option;
    cout << "\n\n" << "[1] Try again\n[2] Main menu" << "\n\n" << "Select option: ";
    cin >> option;

    if (option == 1) {
        generateWithSeed();
    }
}

int main()
{
    system("cls");
    int encodeMethod;
    cout << "[1] Generate password with seed\n[0] Exit\n\nSelect option: ";
    cin >> encodeMethod;

    switch (encodeMethod) {
    case(1):
        generateWithSeed();
        main();
        break;
    }
}
