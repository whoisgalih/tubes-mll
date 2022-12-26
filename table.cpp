//
//  table.cpp
//  tubes-mll
//
//  Created by Galih Akbar on 26/12/22.
//

#include "mll.h"

void tableHorizontalSparator(int col, int colWidth[]) {
    cout << "+";
    
    for (int i = 0; i < col; i++) {
        for (int j = 0; j < colWidth[i] + 2; j++) {
            cout << "-";
        }
        cout << "+";
    }
    
    cout << endl;
}

void tableRow(int col, int colWidth[], string data[]) {
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
