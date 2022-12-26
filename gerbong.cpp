#include "mll.h"
//GERBONG
listGerbong createListGerbong(){
    /*  {Fungsi menginisialisasi list gerbong dan mengembalikan list gerbong yang kosong}
         Catatan : ada pointer first dan last   */
    listGerbong LG;
    LG.first = NULL;
    LG.last = NULL;
    return LG;
}

infotypeGerbong createInfoGerbong(string kelas, int maksPenumpang, string konfigurasiSeat, int hargaTiket){
    /*  {Fungsi menginisialiasi X dan mengembalikan X yang berisi info dari suatu gerbong}    */
    infotypeGerbong X;
    X.kelas = kelas;
    X.maksPenumpang = maksPenumpang;
    X.konfigurasiSeat = konfigurasiSeat;
    X.hargaTiket = hargaTiket;

    return X;
}

adrGerbong createElmGerbong(infotypeGerbong X){
    /* {Fungsi menginisialisasi dan mengalokasi element gerbong, kemudian fungsi mengembalikan element gerbong
    yang infonya ter isi oleh X} */
    adrGerbong P = new elmGerbong;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;

    return P;
}

void insertLastGerbong(kereta &k, adrGerbong P){
    /*  {I.S. list gerbong pada kereta k mungkin kosong, dan element gerbong P
         F.S. element gerbong P ditambahkan pada list gerbong paling terakhir}   */
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
    /*  {I.S. list gerbong pada kereta k mungkin kosong
         F.S. menampilkan seluruh data gerbong yang ada pada kereta k}    */
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
    /*  {Fungsi akan mengembalikan alamat gerbong jika terdapat pada list gerbong
     atau NULL jika tidak terdapat pada list gerbong} */
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
    /*  {I.S. list gerbong mungkin kosong
         F.S. menghapus gerbong dari list gerbong jika gerbong tersebut ada pada list gerbong}   */

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
    /*  {Fungsi akan mengembalikan banyak gerbong dari suatu kereta} */
    int counter = 0;
    adrGerbong P = LG.first;
    while(P!=NULL){
        counter ++;
        P = next(P);
    }
    return counter;
}
