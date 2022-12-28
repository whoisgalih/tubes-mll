#include "mll.h"
#include <sstream>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void clearScreen() {
    system(CLEAR);
}

void pause() {
    fflush(stdin); getchar();
}

string rupiah(int i) {
    stringstream ss;
    ss << "Rp" << i;

    string s;
    ss >> s;


    return s;
}

int intInput(string prompt) {
    cout << prompt;

    // Error handling integer input
    string s;
    int num;
    bool isSuccess = false;

    while (!isSuccess) {
        cin >> s;

        try {
            num = stoi(s);
            isSuccess = true;
        } catch (exception &err) {
            cout << "Input harus integer" << endl;
            cout << prompt;
        }
    }

    return num;
}
