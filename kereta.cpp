#include "mll.h"

// MARK: - Kereta
kereta createKereta(infoKereta info) {
    /*  {Fungsi menginisialisasi kereta dan mengembalikan kereta dengan list penumpang dan list gerbong nya kosong} */
    kereta k;
    k.gerbong = createListGerbong();
    k.penumpang = createListPenumpang();
    k.info = info;

    return k;
}

infoKereta createInfoKereta(string nama, string asal, string tujuan, string tanggal, string jamBerangkat, string jamTiba, int panjangRangkaian,bool makan) {
    /*  {Fungsi menginisialisasi info dan mengembalikan info yang sudah terisi } */
    infoKereta info;
    info.nama = nama;
    info.asal = asal;
    info.tujuan = tujuan;
    info.tanggal = tanggal;
    info.jamBerangkat = jamBerangkat;
    info.jamTiba = jamTiba;
    info.panjangRangkaian = panjangRangkaian;
    info.makan = makan;

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

        cout << "Penumpang " << info(p).nama << " telah ditambahkan ke gerbong " << info(g).kelas << endl;
    }
}

void showKereta(kereta k) {
    /* {I.S. Diberikan kereta k
        F.S. menampilkan data perjalanan dari kereta k} */

    // print info kereta
    infoKereta info = k.info;
    int totalPenumpang = countPenumpang(k);
    string makan;
    if (info.makan){
        makan = "YA";
    }else{
        makan = "TIDAK";
    }
    cout <<
    "Nama Kereta\t\t: " << info.nama << endl <<
    "Asal\t\t\t: " << info.asal << endl <<
    "Tujuan\t\t\t: " << info.tujuan << endl <<
    "Tanggal\t\t\t: " << info.tanggal << endl <<
    "Jam Berangkat\t\t: " << info.jamBerangkat << endl <<
    "Jam Tiba\t\t: " << info.jamTiba << endl <<
    "Panjang Rangkaian\t: " << info.panjangRangkaian << endl <<
    "Total Penumpang\t\t: " << totalPenumpang << endl<<
    "Terdapat Gerbong Makan\t: "<<makan<<endl<<endl;
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

        // delete gerbong
        deleteGerbong(k, g);
        cout << "Gerbong " << kelas << " berhasil di hapus" << endl;
    } else {
        cout << "Gerbong " << kelas << " tidak ditemukan" << endl;
    }
}

adrGerbong maxPenumpang(kereta k) {
    /*  {Fungsi mengembalikan alamat gerbong yang memiliki jumlah peumpang paling banyak dari suatu kereta} */
    if (k.gerbong.first != NULL) {
        adrGerbong p = next(k.gerbong.first);
        adrGerbong maxAdr = k.gerbong.first;
        int maxCount = countPenumpangByGerbong(k, maxAdr);

        while (p != NULL) {
            int temp = countPenumpangByGerbong(k, p);
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
        int minCount = countPenumpangByGerbong(k, minAdr);

        while (p != NULL) {
            int temp = countPenumpangByGerbong(k, p);
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
