#include "mll.h"
#include <sstream>

//Define clear untuk system operasi windows dan selain windows
#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void clearScreen() {
    /* {I.S
        F.S. Procedure untuk menghapus output yang ada di terminal dengan memanfaatkan "CLS"} */
    system(CLEAR);
}

void pause() {
    /* {I.S.
        F.S. Procedure untuk melakukan pause setelah mengeluarkan suatu output dengan memanfaatkan fflush(stdin)} */
    fflush(stdin); getchar();
}

string rupiah(int i) {
    /* {Fungsi menerima suatu data yang bertipe integer kemudian mengubah data tersebut menjadi tipe string
        dan mengembalikan string tersebut yang sudah dilakukan concate dengan string "Rp" } */
    stringstream ss;
    ss << "Rp" << i;

    string s;
    ss >> s;


    return s;
}

int intInput(string prompt) {
    /* {Fungsi untuk menghandle error jika ada input yang seharusnya bertipe integer
        namun diisi dengan data bertipe string, sehingga program tidak exit} */
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

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    
    return s;
}
