#include "mll.h"

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
