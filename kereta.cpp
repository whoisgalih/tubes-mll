#include "mll.h"
// Kereta
kereta createKereta(infoKereta info) {
    kereta k;
    k.gerbong = createListGerbong();
    k.penumpang = createListPenumpang();
    k.info = info;

    return k;
}

infoKereta createInfoKereta(string nama, string asal, string tujuan, string tanggal, string jamBerangkat, string jamTiba, int panjangRangkaian) {
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
    adrGerbong g = searchGerbong(k.gerbong, kelas);
    adrPenumpang p = searchPenumpang(k.penumpang, nama);

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
    adrGerbong g = searchGerbong(k.gerbong, kelas);

    if (g != NULL) {
        // disonnect
        adrPenumpang p = k.penumpang.first;

        while (p != NULL) {
            if (gerbong(p) == g) {
                gerbong(p) = NULL;
            }

            p = next(p);
        }

        deleteGerbong(k.gerbong, kelas); // warn, ini loop seacrh gerbong lagi
    }
}

adrGerbong maxPenumpang(kereta k) {
    if (k.gerbong.first != NULL) {
        adrGerbong p = next(k.gerbong.first);
        adrGerbong maxAdr = k.gerbong.first;
        int maxCount = countPenumpangByGerbong(k.penumpang, info(maxAdr).kelas);

        while (p != NULL) {
            int temp = countPenumpangByGerbong(k.penumpang, info(p).kelas);
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
    if (k.gerbong.first != NULL) {
        adrGerbong p = next(k.gerbong.first);
        adrGerbong minAdr = k.gerbong.first;
        int minCount = countPenumpangByGerbong(k.penumpang, info(minAdr).kelas);

        while (p != NULL) {
            int temp = countPenumpangByGerbong(k.penumpang, info(p).kelas);
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
