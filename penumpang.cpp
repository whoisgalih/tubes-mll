#include "mll.h"
listPenumpang createListPenumpang(){
    listPenumpang LP;
    LP.first = NULL;
    LP.last = NULL;
    return LP;
}

infotypePenumpang createInfoPenumpang(string nama, int usia, string jenisKelamin){
    infotypePenumpang X;
    X.nama = nama;
    X.usia = usia;
    X.jenisKelamin = jenisKelamin;

    return X;
}

adrPenumpang createElmPenumpang(infotypePenumpang X){
    adrPenumpang P = new elmPenumpang;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    gerbong(P) = NULL;

    return P;
}

void insertLastPenumpang(kereta &k, adrPenumpang P){
    if (k.penumpang.first == NULL && k.penumpang.last == NULL){
        k.penumpang.first = P;
        k.penumpang.last = P;
    }else{
        adrPenumpang Q = k.penumpang.last;
        next(Q) = P;
        prev(P) = Q;
        k.penumpang.last = P;
    }
}

void showPenumpang(kereta k){
    cout << "Penumpang dari kereta " << k.info.nama << endl;
    if (k.penumpang.first==NULL){
        cout << "Penumpang Kosong"<<endl;
    }else{
        adrPenumpang P;
        P = k.penumpang.first;
        
        int col = 3;
        int colWidth[] = {8, 4, 10};
        
        string data[] = {"NAMA", "USIA", "KELAMIN"};
        
        tableHorizontalSparator(col, colWidth);
        tableRow(col, colWidth, data);
        tableHorizontalSparator(col, colWidth);
        
        while (P!=NULL){
            string data[] = {info(P).nama, to_string(info(P).usia), info(P).jenisKelamin};
            tableRow(col, colWidth, data);
            
            P = next(P);
        }
        
        tableHorizontalSparator(col, colWidth);
        cout<<endl;
    }

}

adrPenumpang searchPenumpang(listPenumpang LP, string nama){
    adrPenumpang P = LP.first;

    while (P!=NULL){
        if (info(P).nama == nama){
            return P;
        }
        P = next(P);
    }

    return P;
}

void deletePenumpang(listPenumpang &LP, string nama){
    //CEK KALAU KOSONG
    if (LP.first == NULL){
        cout << "List Kosong"<<endl;
    }else{
        //CEK APAKAH NAMA ADA DI LIST
        adrPenumpang pen = searchPenumpang(LP, nama);
        if (pen != NULL){
            if (pen == LP.first){ // CEK APAKAH ADA DI FIRST
                // Delete First
                LP.first = next(pen);
                next(pen) = NULL;
                prev(LP.first) = NULL;
            }else if (pen == LP.last){ // CEK APAKAH ADA DI LAST
                // Delete Last
                LP.last = prev(pen);
                prev(pen) = NULL;
                next(LP.last) = NULL;
            }else{
                // Delete After
                adrPenumpang Q = prev(pen);
                next(Q) = next(pen);
                prev(next(pen)) = Q;
                next(pen) = NULL;
                prev(pen) = NULL;
            }
        } else {
            cout << "Nama "<< nama << " tidak terdaftar" << endl;
        }
    }
}

void showPenumpangByGerbong(kereta k, string kelas){
    cout << "Penumpang dari kereta " << k.info.nama << " di gerbong " << kelas << endl;
    if (k.penumpang.first == NULL){
        cout << "List Penumpang Kosong"<<endl;
    }else{
        adrPenumpang P = k.penumpang.first;
        
        int col = 4;
        int colWidth[] = {8, 4, 10, 12};
        
        string data[] = {"NAMA", "USIA", "KELAMIN", "KELAS"};
        
        tableHorizontalSparator(col, colWidth);
        tableRow(col, colWidth, data);
        tableHorizontalSparator(col, colWidth);
        
        while (P!=NULL){
            if (gerbong(P)!=NULL){
                if (info(gerbong(P)).kelas == kelas){
                    string data[] = {info(P).nama, to_string(info(P).usia), info(P).jenisKelamin, info(gerbong(P)).kelas};
                        tableRow(col, colWidth, data);

                }
            }
            P = next(P);
        }
        
        tableHorizontalSparator(col, colWidth);
        cout<<endl;
    }
}

int countPenumpangByGerbong(listPenumpang LP,string kelas){
    int counter = 0;
    if (LP.first==NULL){
        return 0;
    }else{
        adrPenumpang P = LP.first;
        while (P!=NULL){
            if (gerbong(P)!=NULL){
                if (info(gerbong(P)).kelas==kelas){
                    counter++;
                }
            }
            P = next(P);
        }
        return counter;
    }
}
