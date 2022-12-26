#include "mll.h"
// Kereta
kereta createKereta(infoKereta info) {
    /*  {Fungsi menginisialisasi kereta dan mengembalikan kereta dengan list penumpang dan list gerbong nya kosong} */
    kereta k;
    k.gerbong = createListGerbong();
    k.penumpang = createListPenumpang();
    k.info = info;

    return k;
}

infoKereta createInfoKereta(string nama, string asal, string tujuan, string tanggal, string jamBerangkat, string jamTiba, int panjangRangkaian) {
    /*  {Fungsi menginisialisasi info dan mengembalikan info yang sudah terisi } */
    infoKereta info;
    info.nama = nama;
    info.asal = asal;
    info.tujuan = tujuan;
    info.tanggal = tanggal;
    info.jamBerangkat = jamBerangkat;
    info.jamTiba = jamTiba;
    info.panjangRangkaian = panjangRangkaian;

    return info;
}

void connectPenumpangGerbong(kereta &k, string nama, string kelas) {
    /* {I.S. diberikan kereta k yang mungkin kosong dan nama, kelas gerbong yang mungkin tidak ada pada list
        F.S. penumpang dengan nama yang diberikan terhubung dengan gerbong yang memiliki kelas yang diberikan} */
        
    adrGerbong g = searchGerbong(k, kelas);
    adrPenumpang p = searchPenumpang(k, nama);

    if (g == NULL || p == NULL) {
        if (g == NULL) {
            cout << "Gerbong " << kelas << " tidak ditemukan" << endl;
        }
        if (p == NULL) {
            cout << "Penumpang " << nama << " tidak ditemukan" << endl;
        }
    } else {
        gerbong(p) = g;
    }
}

void showKereta(kereta k) {
    /* {I.S. Diberikan kereta k
        F.S. menampilkan data perjalanan dari kereta k} */

    // print info kereta
    infoKereta info = k.info;
    cout <<
    "Nama\t\t\t\t: " << info.nama << endl <<
    "Asal\t\t\t\t: " << info.asal << endl <<
    "Tujuan\t\t\t\t: " << info.tujuan << endl <<
    "Tanggal\t\t\t\t: " << info.tanggal << endl <<
    "Jam Berangkat\t\t: " << info.jamBerangkat << endl <<
    "Jam Tiba\t\t\t: " << info.jamTiba << endl <<
    "Panjang Rangkaian\t: " << info.panjangRangkaian << endl << endl;

//    adrGerbong g = k.gerbong.first;
//
//    while (g != NULL) {
//        // print info gerbong
//        cout <<
//        "KELAS\t\t\t\t: " << info(g).kelas << endl <<
//        "MAKSIMAL PENUMPANG\t: " << info(g).maksPenumpang << endl <<
//        "KONFIGURASI SEAT\t: "  << info(g).konfigurasiSeat << endl <<
//        "HARGA TIKET\t\t\t: " << info(g).hargaTiket << endl;
//
//        // print info penumpang
//        adrPenumpang p = k.penumpang.first;
//        while (p != NULL){
//            if (gerbong(p) == g) {
//                cout << info(p).nama << info(p).usia << info(p).jenisKelamin << endl;
//            }
//            p = next(p);
//        }
//
//        cout << endl;
//
//        g = next(g);
//    }
}

int countPenumpang(kereta k){
    /*  {Fungsi mengembalikan banyak total keseluruhan dari kereta k} */
    int counter = 0;
    adrPenumpang P = k.penumpang.first;
    if (P == NULL){
        return 0;
    }else{
        while (P!=NULL){
            counter++;
            P = next(P);
        }
        return counter;
    }
}


void deleteDisconnectGerbong(kereta &k, string kelas) {
    /*  {I.S. gerbong dengan kelas yang dicari bisa saja tidak terdapat di kereta k
         F.S. jika gerbong terdapat pada kereta k maka gerbong dihapus dari kereta k dan penumpang yang menaiki gerbong tersebut diubah menjadi NULL} */

    adrGerbong g = searchGerbong(k, kelas);

    if (g != NULL) {
        // disonnect
        adrPenumpang p = k.penumpang.first;

        while (p != NULL) {
            if (gerbong(p) == g) {
                gerbong(p) = NULL;
            }

            p = next(p);
        }

        deleteGerbong(k, kelas); // warn, ini loop seacrh gerbong lagi
    }
}

adrGerbong maxPenumpang(kereta k) {
    /*  {Fungsi mengembalikan alamat gerbong yang memiliki jumlah peumpang paling banyak dari suatu kereta} */
    if (k.gerbong.first != NULL) {
        adrGerbong p = next(k.gerbong.first);
        adrGerbong maxAdr = k.gerbong.first;
        int maxCount = countPenumpangByGerbong(k, info(maxAdr).kelas);

        while (p != NULL) {
            int temp = countPenumpangByGerbong(k, info(p).kelas);
            if (temp > maxCount) {
                maxCount = temp;
                maxAdr = p;
            }

            p = next(p);
        }

        return maxAdr;
    }

    return NULL;
}


adrGerbong minPenumpang(kereta k) {
    /*  {Fungsi mengembalikan alamat gerbong yang memiliki jumlah penumpang paling sedikit dari suatu gerbong} */
    if (k.gerbong.first != NULL) {
        adrGerbong p = next(k.gerbong.first);
        adrGerbong minAdr = k.gerbong.first;
        int minCount = countPenumpangByGerbong(k, info(minAdr).kelas);

        while (p != NULL) {
            int temp = countPenumpangByGerbong(k, info(p).kelas);
            if (temp < minCount) {
                minCount = temp;
                minAdr = p;
            }

            p = next(p);
        }

        return minAdr;
    }

    return NULL;
}
