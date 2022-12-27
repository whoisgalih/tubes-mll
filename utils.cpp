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
