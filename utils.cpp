#include "mll.h"

void clearScreen() {
    #ifdef WINDOWS
        system("cls");
    #else
        // Assume POSIX
        system("clear");
    #endif
}

void pause() {
    fflush(stdin); getchar();
}
