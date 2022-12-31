//
//  table.cpp
//  tubes-mll
//
//  Created by Galih Akbar on 26/12/22.
//

#include "mll.h"

void tableHorizontalSparator(vector<int> colWidth) {
    /* {I.S. Terdefinisi lebar masing-masing kolom
        F.S. Menampilkan output berupa "-" dan "+" sebagai pembatas horizontal} */
    int col = colWidth.size();

    cout << "+";

    for (int i = 0; i < col; i++) {
        for (int j = 0; j < colWidth[i] + 2; j++) {
            cout << "-";
        }
        cout << "+";
    }

    cout << endl;
}

void tableRow(vector<int> colWidth, vector<string> data) {
    /* {I.S. Terdefinisi lebar dan data masing-masing kolom
        F.S. Menampilkan data yang terpisahkan oleh "|" } */
    int col = colWidth.size();

    cout << "|";

    for (int i = 0; i < col; i++) {
        cout << " " << data[i];

        for (int j = 0; j < colWidth[i] - data[i].length(); j++) {
            cout << " ";
        }

        cout << " |";
    }

    cout << endl;
}

vector<int> colWidth(vector<vector<string>> &t) {
    /* {I.S. Terdefinisi kolom dan baris
        F.S. Mengembalikan panjang maksimal masing-masing kolom} */
    vector<int> colw;

    for (int i = 0; i < t[0].size(); i++) {
        int max = 0;

        for (int j = 0; j < t.size(); j++) {
            int len = t[j][i].size();

            if (len > max) {
                max = len;
            }
        }

        colw.push_back(max);
    }

    return colw;
}

void table(vector<vector<string>> &t) {
    /* {I.S. Terdefinisi kolom dan baris
        F.S. Membuat tabel menggunakan procedure tableRow dan procedure tableHorizonalSparator} */
    vector<int> colw = colWidth(t);

    tableHorizontalSparator(colw);
    tableRow(colw, t[0]);
    tableHorizontalSparator(colw);

    for (int i = 1; i < t.size(); i++) {
        tableRow(colw, t[i]);
    }

    tableHorizontalSparator(colw);
}
