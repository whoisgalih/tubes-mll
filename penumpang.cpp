#include "mll.h"

// MARK: - Penumpang
listPenumpang createListPenumpang(){
    /*  {Fungsi menginisialisasi list penumpang dan mengembalikan list penumpang yang kosong}
        Catatan : ada pointer first dan last    */

    listPenumpang LP;
    LP.first = NULL;
    LP.last = NULL;
    return LP;
}

infotypePenumpang createInfoPenumpang(string nama, int usia, string jenisKelamin){
    /*  {Fungsi menginisialiasi X dan mengembalikan X yang berisi info dari seorang penumpang}    */
    infotypePenumpang X;
    X.nama = nama;
    X.usia = usia;
    X.jenisKelamin = jenisKelamin;

    return X;
}

adrPenumpang createElmPenumpang(infotypePenumpang X){
    /* {Fungsi menginisialisasi dan mengalokasi element penumpang, kemudian fungsi mengembalikan element penumpang
        yang infonya ter isi oleh X} */
    adrPenumpang P = new elmPenumpang;
    info(P) = X;
    next(P) = NULL;
    prev(P) = NULL;
    gerbong(P) = NULL;

    return P;
}

void insertLastPenumpang(kereta &k, adrPenumpang P){
    /*  {I.S. list penumpang pada kereta k mungkin kosong, dan element penumpang P
         F.S. element penumpang P ditambahkan pada list penumpang paling terakhir}   */
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
    /*  {I.S. list penumpang pada kereta k mungkin kosong
         F.S. menampilkan seluruh data penumpang yang ada pada kereta k}    */
    cout << "Penumpang dari kereta " << k.info.nama << endl;
    if (k.penumpang.first==NULL){
        cout << "Penumpang Kosong"<<endl;
    }else{
        adrPenumpang P;
        P = k.penumpang.first;

        int col = 5;
        int colWidth[] = {30,4,10,10,8};

        string data[] = {"NAMA", "USIA", "KATEGORI", "KELAMIN", "GERBONG"};

        tableHorizontalSparator(col, colWidth);
        tableRow(col, colWidth, data);
        tableHorizontalSparator(col, colWidth);

        string gerbong,kategori;
        while (P!=NULL){
            if (gerbong(P)!=NULL){
                gerbong = "YA";
            }else{
                gerbong = "TIDAK";
            }
            if (info(P).usia>0 && info(P).usia<17){
                kategori = "anak-anak";
            }else if(info(P).usia>16&&info(P).usia<61){
                kategori = "dewasa";
            }else{
                kategori = "lansia";
            }
            string data[] = {info(P).nama, to_string(info(P).usia),kategori, info(P).jenisKelamin,gerbong};
            tableRow(col, colWidth, data);

            P = next(P);
        }

        tableHorizontalSparator(col, colWidth);
        cout<<endl;
    }

}

adrPenumpang searchPenumpang(kereta k, string nama){
    /*  {Fungsi akan mengembalikan alamat penumpang jika terdapat pada list penumpang
         atau NULL jika tidak terdapat pada list penumpang}     */

    adrPenumpang P = k.penumpang.first;

    while (P!=NULL){
        if (info(P).nama == nama){
            return P;
        }
        P = next(P);
    }

    return P;
}

void deletePenumpang(kereta &k, string nama){
    /*  {I.S. list penumpang mungkin kosong
         F.S. menghapus penumpang dari list penumpang jika penumpang tersebut ada pada list penumpang}   */

    // CEK KALAU KOSONG
    if (k.penumpang.first == NULL){
        cout << "List Kosong"<<endl;
    }else{
        // CEK APAKAH NAMA ADA DI LIST
        adrPenumpang pen = searchPenumpang(k, nama);
        if (pen != NULL){
            if (pen == k.penumpang.first){ // CEK APAKAH ADA DI FIRST
                // Delete First
                k.penumpang.first = next(pen);
                next(pen) = NULL;
                prev(k.penumpang.first) = NULL;
            }else if (pen == k.penumpang.last){ // CEK APAKAH ADA DI LAST
                // Delete Last
                k.penumpang.last = prev(pen);
                prev(pen) = NULL;
                next(k.penumpang.last) = NULL;
            }else{
                // Delete After
                adrPenumpang Q = prev(pen);
                next(Q) = next(pen);
                prev(next(pen)) = Q;
                next(pen) = NULL;
                prev(pen) = NULL;
            }
            cout << "Penumpang "<< nama << " behasil dihapus" << endl;
        } else {
            cout << "Penumpang "<< nama << " tidak terdaftar" << endl;
        }
    }
}

void showPenumpangByGerbong(kereta k, adrGerbong g){
    /*  {I.S. list penumpang pada kereta k mungkin kosong
         F.S. mencetak seluruh penumpang berdasarkan kelas gerbong}   */
    if (k.penumpang.first == NULL){
        cout << "List Penumpang Kosong" << endl;
    } else if (g == NULL) {
        cout << "Gerbong tidak ada" << endl;
    } else {
        cout << "Penumpang dari kereta " << k.info.nama << " di gerbong " << info(g).kelas << endl;

        adrPenumpang P = k.penumpang.first;

        int col = 4;
        int colWidth[] = {30, 4, 10, 18};

        string data[] = {"NAMA", "USIA", "KELAMIN", "KELAS"};

        tableHorizontalSparator(col, colWidth);
        tableRow(col, colWidth, data);
        tableHorizontalSparator(col, colWidth);

        while (P != NULL){
            if (gerbong(P) == g){
                string data[] = {info(P).nama, to_string(info(P).usia), info(P).jenisKelamin, info(gerbong(P)).kelas};
                    tableRow(col, colWidth, data);
            }

            P = next(P);
        }

        tableHorizontalSparator(col, colWidth);
        cout<<endl;
    }
}


int countPenumpangByGerbong(kereta k, adrGerbong g) {
    /*  {Fungsi akan mengembalikan banyak penumpang dari suatu gerbong} */

    int counter = 0;
    if (k.penumpang.first == NULL || g == NULL){
        return 0;
    }else{
        adrPenumpang P = k.penumpang.first;
        while (P!=NULL){
            if (gerbong(P) == g){
                counter++;
            }

            P = next(P);
        }
        return counter;
    }
}
