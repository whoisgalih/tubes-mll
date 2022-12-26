#include "mll.h"
//GERBONG
listGerbong createListGerbong(){
    listGerbong LG;
    LG.first = NULL;
    LG.last = NULL;
    return LG;
}

infotypeGerbong createInfoGerbong(string kelas, int maksPenumpang, string konfigurasiSeat, int hargaTiket){
    infotypeGerbong X;
    X.kelas = kelas;
    X.maksPenumpang = maksPenumpang;
    X.konfigurasiSeat = konfigurasiSeat;
    X.hargaTiket = hargaTiket;

    return X;
}

adrGerbong createElmGerbong(infotypeGerbong X){
    adrGerbong P = new elmGerbong;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void insertLastGerbong(kereta &k, adrGerbong P){
    if (k.gerbong.first == NULL && k.gerbong.first == NULL){
        k.gerbong.first = P;
        k.gerbong.last = P;
    }else{
        adrGerbong Q = k.gerbong.last;
        next(Q) = P;
        prev(P) = Q;
        k.gerbong.last = P;
    }
    k.info.panjangRangkaian++;
}

void showGerbong(kereta k){
    cout << "Gerbong dari kereta " << k.info.nama << endl;
    if (k.gerbong.first == NULL){
        cout << "Gerbong Kosong"<<endl;
    }else{
        adrGerbong P;
        P = k.gerbong.first;
        
        int col = 4;
        int colWidth[] = {12, 18, 16, 12};
        
        string data[] = {"KELAS", "MAKSIMAL PENUMPANG", "KONFIGURASI SEAT", "HARGA TIKET"};
        
        tableHorizontalSparator(col, colWidth);
        tableRow(col, colWidth, data);
        tableHorizontalSparator(col, colWidth);
        
        while (P!=NULL){
            string data[] = {info(P).kelas, to_string(info(P).maksPenumpang), info(P).konfigurasiSeat, to_string(info(P).hargaTiket)};
            
            
            tableRow(col, colWidth, data);
            P = next(P);
        }
        
        tableHorizontalSparator(col, colWidth);
        cout<<endl;
    }
}

adrGerbong searchGerbong(listGerbong LG, string kelas){
    adrGerbong P = LG.first;

    while(P!=NULL){
        if (info(P).kelas == kelas){
            return P;
        }
        P = next(P);
    }

    return P;
}

void deleteGerbong(listGerbong &LG, string kelas) {
    //CEK KALAU KOSONG
    if (LG.first == NULL){
        cout << "List Kosong"<<endl;
    }else{
        //CEK APAKAH NAMA ADA DI LIST
        adrGerbong ger = searchGerbong(LG, kelas);
        if (ger != NULL){
            if (ger == LG.first){ // CEK APAKAH ADA DI FIRST
                // Delete First
                LG.first = next(ger);
                next(ger) = NULL;
                prev(LG.first) = NULL;
            }else if (ger == LG.last){ // CEK APAKAH ADA DI LAST
                // Delete Last
                LG.last = prev(ger);
                prev(ger) = NULL;
                next(LG.last) = NULL;
            }else{
                // Delete After
                adrGerbong Q = prev(ger);
                next(Q) = next(ger);
                prev(next(ger)) = Q;
                next(ger) = NULL;
                prev(ger) = NULL;
            }
        } else {
            cout << "Kelas " << kelas << " tidak terdaftar" << endl;
        }
    }
}

int countGerbong(listGerbong LG){
    int counter = 0;
    adrGerbong P = LG.first;
    while(P!=NULL){
        counter ++;
        P = next(P);
    }
    return counter;
}
