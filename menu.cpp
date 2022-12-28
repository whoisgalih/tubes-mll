#include "mll.h"

// MARK: - Menu
string menu() {
    clearScreen();
    string inputUser;
    cout << "===== SELAMAT DATANG DI PROGRAM KERETA =====" << endl;
    cout << "1. Kereta Api Lokal" << endl;
    cout << "2. Kereta Api Antar Kota" << endl;
    cout << "0. Exit Program" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    cout << endl;

    return inputUser;
}

string menuLokal() {
    clearScreen();
    string inputUser;
    cout << "===== SILAHKAN PILIH KERETA =====" << endl;
    cout << "1. Bandung Raya Ekonomi" << endl;
    cout << "0. Back" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    cout << endl;

    return inputUser;
}

string menuAntarKota()
{
    clearScreen();
    string inputUser;
    cout << "===== SILAHKAN PILIH KERETA =====" << endl;
    cout << "1. Turangga" << endl;
    cout << "2. Argo Parahyangan" << endl;
    cout << "0. Back" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;
    cout << endl;

    return inputUser;
}

string menuKereta(kereta &k) {
    clearScreen();
    cout << "=============== DATA KERETA ==============="<<endl;
    showKereta(k);

    string inputUser;
    cout << "===== SILAHKAN PILIH OPSI =====" << endl;
    cout << "1. Menambahkan Gerbong" << endl;
    cout << "2. Menambahkan Penumpang" << endl;
    cout << "3. Mencari Penumpang" << endl;
    cout << "4. Menampilkan Data Gerbong" << endl;
    cout << "5. Menampilkan Data Penumpang" << endl;
    cout << "6. Menghapus Gerbong" << endl;
    cout << "7. Menghapus Penumpang" << endl;
    cout << "8. Menampilkan Data Penumpang Berdasarkan Gerbong" << endl;
    cout << "9. Menampilkan Jumlah Penumpang Berdasarkan Gerbong" << endl;
    cout << "10. Menampilkan Data Gerbong Dengan Jumlah Penumpang Paling Sedikit" << endl;
    cout << "11. Menampilkan Data Gerbong Dengan Jumlah Penumpang Paling Banyak" << endl;
    cout << "0. Back" << endl;
    cout << "Masukkan pilihan: ";
    cin >> inputUser;

    if (inputUser == "0") {

    } else if (inputUser == "1"){
        infoGerbong info;

        cout << "Kelas\t\t\t: ";
        getline(cin, info.kelas, '\n');
        getline(cin, info.kelas, '\n');
        cout << "Maksimal Penumpang\t: ";
        cin >> info.maksPenumpang;
        cout << "Konfigurasi seat\t: ";
        cin >> info.konfigurasiSeat;
        cout << "Harga tiket\t\t: ";
        cin >> info.hargaTiket;

        insertLastGerbong(k, createElmGerbong(info));

        pause();
    }else if (inputUser == "2"){
        infoPenumpang info;
        string kelas;

        cout << "Nama\t\t: ";
        getline(cin, info.nama, '\n');
        getline(cin, info.nama, '\n');
        cout << "Usia\t\t: ";
        cin >> info.usia;
        cout << "Jenis Kelamin\t: ";
        getline(cin, info.jenisKelamin, '\n');
        getline(cin, info.jenisKelamin, '\n');
        cout << "Gerbong\t\t: ";
        getline(cin, kelas, '\n');

        if (searchGerbong(k, kelas) != NULL) {
            if (info.usia>0){
                insertLastPenumpang(k, createElmPenumpang(info));
                connectPenumpangGerbong(k, info.nama, kelas);
                cout << "Penumpang " << info.nama << " berhasil ditambahkan ke kereta " << k.info.nama << " di gerbong " << kelas << endl;
            }else{
                cout << "Usia tidak valid."<<endl;
            }
        }else{
            cout << "Gerbong Tidak Ada. Insert Penumpang Gagal!"<<endl;
        }

        pause();
    }else if (inputUser == "3"){
        string nama;
        cout << "Nama penumpang yang dicari: ";
        getline(cin, nama, '\n');
        getline(cin, nama, '\n');

        adrPenumpang p = searchPenumpang(k, nama);

        if (p) {
            cout << "Terdapat penumpang bernama " << nama << endl;
            cout << "Jenis kelamin\t: " << info(p).jenisKelamin << endl;
            cout << "Umur\t\t: " << info(p).usia << endl;
            cout << "Gerbong\t\t: " << info(gerbong(p)).kelas << endl;
            cout << "Kereta\t\t: " << k.info.nama << endl;
        } else {
            cout << "Tidak terdapat penumpang bernama " << nama << endl;
        }

        pause();
    }else if (inputUser == "4"){
        showGerbong(k);
        pause();
    }else if (inputUser == "5"){
        showPenumpang(k);
        pause();
    }else if (inputUser == "6"){
        string kelas;
        cout<<"Masukkan gerbong: ";
        getline(cin, kelas, '\n');
        getline(cin, kelas, '\n');
        deleteDisconnectGerbong(k,kelas);
        pause();
    }else if (inputUser == "7"){
        string nama;
        cout<<"Masukkan nama: ";
        getline(cin, nama, '\n');
        getline(cin, nama, '\n');
        deletePenumpang(k, nama);
        pause();
    }else if (inputUser == "8"){
        // Menampilkan Data Penumpang Berdasarkan Gerbong Loop
        adrGerbong g = k.gerbong.first;

        while (g != NULL) {
            showPenumpangByGerbong(k, g);

            g = next(g);
        }
        pause();
    }else if (inputUser == "9"){
        // Menampilkan Jumlah Penumpang Berdasarkan Gerbong Loop
        cout << "Jumlah penumpang dalam gerbong:" << endl;
        adrGerbong g = k.gerbong.first;

        while (g != NULL) {
            cout << info(g).kelas << "\t: " << countPenumpangByGerbong(k, g) << endl;

            g = next(g);
        }
        pause();
    }else if (inputUser == "10"){
        // Menampilkan Gerbong Dengan Jumlah Penumpang Paling Sedikit
        adrGerbong g = minPenumpang(k);
        cout << "Gerbong dengan penumpang paling sedikit adalah " << info(g).kelas << endl;
        cout <<
        "Banyak Penumpang\t: "<< countPenumpangByGerbong(k, g)<<endl<<
        "Kelas\t\t\t: " << info(g).kelas << endl <<
        "Maksimal Penumpang\t: " << info(g).maksPenumpang << endl <<
        "Sisa Kursi\t\t: "<<info(g).maksPenumpang - countPenumpangByGerbong(k, g)<<endl<<
        "Konfigurasi Seat\t: " << info(g).konfigurasiSeat << endl <<
        "Harga Tiket\t\t: " << rupiah(info(g).hargaTiket) << endl << endl;
        pause();
    }else if (inputUser == "11"){
        // Menampilkan Gerbong Dengan Jumlah Penumpang Paling Banyak
        adrGerbong g = maxPenumpang(k);
        cout << "Gerbong dengan penumpang paling banyak adalah " << info(g).kelas << endl;
        cout <<
        "Banyak Penumpang\t: "<<countPenumpangByGerbong(k, g)<<endl<<
        "Kelas\t\t\t: " << info(g).kelas << endl <<
        "Maksimal Penumpang\t: " << info(g).maksPenumpang << endl <<
        "Sisa Kursi\t\t: "<<info(g).maksPenumpang - countPenumpangByGerbong(k, g)<<endl<<
        "Konfigurasi Seat\t: " << info(g).konfigurasiSeat << endl <<
        "Harga Tiket\t\t: " << rupiah(info(g).hargaTiket) << endl << endl;
        pause();
    } else {
        invalidInput();
    }
    return inputUser;
}

void invalidInput() {
    cout << "Maaf input tidak valid."<<endl;
    pause();
}
