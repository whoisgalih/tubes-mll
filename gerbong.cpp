#include "mll.h"

// MARK: - Gerbong
listGerbong createListGerbong(){
    /*  {Fungsi menginisialisasi list gerbong dan mengembalikan list gerbong yang kosong}
     Catatan : ada pointer first dan last   */
    listGerbong LG;
    LG.first = NULL;
    LG.last = NULL;
    return LG;
}

infotypeGerbong createInfoGerbong(string kelas, int maksPenumpang, string konfigurasiSeat, int hargaTiket) {
    /*  {Fungsi menginisialiasi X dan mengembalikan X yang berisi info dari suatu gerbong}    */
    infotypeGerbong X;
    X.kelas = kelas;
    X.maksPenumpang = maksPenumpang;
    X.konfigurasiSeat = konfigurasiSeat;
    X.hargaTiket = hargaTiket;
    X.sisaKursi = maksPenumpang;
    
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
    if (k.gerbong.first == NULL && k.gerbong.first == NULL){ // Jika Gerbong Kosong
        k.gerbong.first = P;
        k.gerbong.last = P;
    }else{
        adrGerbong Q = k.gerbong.last;
        next(Q) = P;
        prev(P) = Q;
        k.gerbong.last = P;
    }
    k.info.panjangRangkaian++; // Panjang Rangkaian Bertambah
    
    cout << "Gerbong " << info(P).kelas << " berhasil ditambahkan ke kereta " << k.info.nama << endl;
}

void showGerbong(kereta k){
    /*  {I.S. list gerbong pada kereta k mungkin kosong
     F.S. menampilkan seluruh data gerbong yang ada pada kereta k}  */
    cout << "Gerbong dari kereta " << k.info.nama << endl;
    adrGerbong P;
    P = k.gerbong.first;
    
    vector<vector<string>> t;
    
    t.push_back({"KELAS", "MAKSIMAL PENUMPANG", "SISA KURSI","KONFIGURASI SEAT", "HARGA TIKET"});
    
    while (P!=NULL){
        t.push_back({info(P).kelas, to_string(info(P).maksPenumpang),to_string(info(P).sisaKursi), info(P).konfigurasiSeat, rupiah(info(P).hargaTiket)});
        
        P = next(P);
    }
    
    table(t);
    cout<<endl;
}


adrGerbong searchGerbong(kereta k, string kelas){
    /*  {Fungsi akan mengembalikan alamat gerbong jika terdapat pada list gerbong
     atau NULL jika tidak terdapat pada list gerbong} */
    
    adrGerbong P = k.gerbong.first;
    
    while(P!=NULL){
        if (toLower(info(P).kelas) == toLower(kelas)){
            return P;
        }
        P = next(P);
    }
    
    return P;
}


void deleteGerbong(kereta &k, adrGerbong g) {
    /*  {I.S. list gerbong mungkin kosong
     F.S. menghapus gerbong dari list gerbong jika gerbong tersebut ada pada list gerbong}   */
    
    // CEK KALAU KOSONG
    if (k.gerbong.first == NULL){
        cout << "List Kosong"<<endl;
    }else{
        if (g != NULL){
            if (g == k.gerbong.first){ // CEK APAKAH ADA DI FIRST
                // Delete First
                if (k.gerbong.first == k.gerbong.last) {
                    k.gerbong.last = NULL;
                } else {
                    prev(k.gerbong.first) = NULL;
                }
                
                k.gerbong.first = next(g);
                next(g) = NULL;
            }else if (g == k.gerbong.last){ // CEK APAKAH ADA DI LAST
                // Delete Last
                k.gerbong.last = prev(g);
                prev(g) = NULL;
                next(k.gerbong.last) = NULL;
            }else{
                // Delete After
                adrGerbong Q = prev(g);
                next(Q) = next(g);
                prev(next(g)) = Q;
                next(g) = NULL;
                prev(g) = NULL;
            }
        } else {
            cout << "Kelas " << info(g).kelas << " tidak terdaftar" << endl;
        }
    }
    
    k.info.panjangRangkaian--;
}


int countGerbong(kereta k) {
    /*  {Fungsi akan mengembalikan banyak gerbong dari suatu kereta} */
    
    int counter = 0;
    adrGerbong P = k.gerbong.first;
    while(P!=NULL){
        counter ++;
        P = next(P);
    }
    return counter;
}
