#include "mll.h"

// MARK: - Menu
string menu() {
    /* {Fungsi akan menampilkan pilihan menu yang disediakan program,
        kemudian fungsi akan mengembalikan suatu string yang menandakan user memilih menu nomor berapa} */
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
    /* {Fungsi akan menampilkan pilihan menu yang disediakan program,
        kemudian fungsi akan mengembalikan suatu string yang menandakan user memilih menu nomor berapa} */
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

string menuAntarKota(){
    /* {Fungsi akan menampilkan pilihan menu yang disediakan program,
        kemudian fungsi akan mengembalikan suatu string yang menandakan user memilih menu nomor berapa} */
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
    /* {Fungsi akan menampilkan pilihan menu yang disediakan program,
        kemudian fungsi akan mengembalikan suatu string yang menandakan user memilih menu nomor berapa} */
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
        string kelas, konfigurasiSeat;
        int maksPenumpang, hargaTiket;

        cout << "Kelas Gerbong\t\t: ";
        getline(cin, kelas, '\n');
        getline(cin, kelas, '\n');
        maksPenumpang = intInput("Maksimal Penumpang\t: ");
        cout << "Konfigurasi seat\t: ";
        cin >> konfigurasiSeat;
        hargaTiket = intInput("Harga tiket\t\t: ");

        insertLastGerbong(k, createElmGerbong(createInfoGerbong(kelas, maksPenumpang, konfigurasiSeat, hargaTiket)));

        pause();
    }else if (inputUser == "2"){
        infoPenumpang info;
        string kelas,nama,jenisKelamin;
        int nik,usia;

        cout << "Kelas Gerbong\t: ";
        getline(cin, kelas, '\n');
        getline(cin, kelas, '\n');

        if (searchGerbong(k, kelas) != NULL) {
            nik = intInput("NIK\t\t: ");
            if (searchPenumpang(k, "", nik)==NULL){
                cout << "Nama\t\t: ";
                getline(cin, nama, '\n');
                getline(cin, nama, '\n');

                usia = intInput("Usia\t\t: ");
                while (usia < 0) {
                    cout << "Usia tidak valid. Usia harus positif" << endl;
                    usia = intInput("Usia\t\t: ");
                }

                cout << "Jenis Kelamin\t: ";
                getline(cin, jenisKelamin, '\n');
                getline(cin, jenisKelamin, '\n');


                insertLastPenumpang(k, createElmPenumpang(createInfoPenumpang(nama,usia,jenisKelamin,nik)));
                connectPenumpangGerbong(k, nama, kelas);
                cout << "Penumpang " << nama << " berhasil ditambahkan ke kereta " << k.info.nama << " di gerbong " << kelas << endl;
            } else {
                cout << "NIK sudah terdaftar" << endl;
            }
            
        }else{
            cout << "Gerbong Tidak Ada. Insert Penumpang Gagal!"<<endl;
        }

        pause();
    }else if (inputUser == "3"){
        string pilihan;
        cout << "1. Mencari berdasarkan NIK"<<endl;
        cout << "2. Mencari berdasarkan nama"<<endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        if (pilihan == "1"){
            int nik;
            nik = intInput("NIK penumpang yang dicari: ");
            adrPenumpang p = searchPenumpang(k,"",nik);
            if (p) {
                cout << "Terdapat penumpang bernama " << info(p).nama << endl;
                cout << "Usia\t\t: " << info(p).usia << endl;
                cout << "Kategori \t: "<< info(p).kategori<<endl;
                cout << "Jenis kelamin\t: " << info(p).jenisKelamin << endl;
                cout << "Gerbong\t\t: " << info(gerbong(p)).kelas << endl;
                cout << "Kereta\t\t: " << k.info.nama << endl;
            } else {
                cout << "Tidak terdapat penumpang dengan NIK " << nik << endl;
            }
            pause();
        }else if (pilihan == "2"){
            string nama;
            cout << "Nama penumpang yang dicari: ";
            getline(cin, nama, '\n');
            getline(cin, nama, '\n');

            adrPenumpang p = searchPenumpang(k, nama,NULL);

            if (p) {
                cout << "Terdapat penumpang bernama " << nama << endl;
                cout << "Usia\t\t: " << info(p).usia << endl;
                cout << "Kategori \t: "<< info(p).kategori<<endl;
                cout << "Jenis kelamin\t: " << info(p).jenisKelamin << endl;
                cout << "Gerbong\t\t: " << info(gerbong(p)).kelas << endl;
                cout << "Kereta\t\t: " << k.info.nama << endl;
            } else {
                cout << "Tidak terdapat penumpang bernama " << nama << endl;
            }
            pause();
        }else{
            invalidInput();
        }
    }else if (inputUser == "4"){
        showGerbong(k);
        pause();
    }else if (inputUser == "5"){
        showPenumpang(k);
        pause();
    }else if (inputUser == "6"){
        string kelas;
        cout<<"Kelas Gerbong: ";
        getline(cin, kelas, '\n');
        getline(cin, kelas, '\n');
        deleteDisconnectGerbong(k,kelas);
        pause();
    }else if (inputUser == "7"){
        string pilihan;
        cout << "1. Menghapus berdasarkan NIK"<<endl;
        cout << "2. Menghapus berdasarkan nama"<<endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        if (pilihan == "1"){
            int nik;
            nik = intInput("Masukkan NIK: ");
            deletePenumpang(k,"", nik);
            pause();
        }else if (pilihan == "2"){
            string nama;
            cout<<"Masukkan nama: ";
            getline(cin, nama, '\n');
            getline(cin, nama, '\n');
            deletePenumpang(k, nama,NULL);
            pause();
        }else{
            invalidInput();
        }
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

        vector<vector<string>> t;

        t.push_back({"KELAS","JUMLAH PENUMPANG"});

        while (g != NULL) {
            t.push_back({info(g).kelas,to_string(countPenumpangByGerbong(k,g))});
            g = next(g);
        }

        table(t);

        pause();
    }else if (inputUser == "10"){
        // Menampilkan Gerbong Dengan Jumlah Penumpang Paling Sedikit
        adrGerbong g = minPenumpang(k);

        if (g != NULL) {
            cout << "Gerbong dengan penumpang paling sedikit adalah " << info(g).kelas << endl;
            cout <<
            "Kelas\t\t\t: " << info(g).kelas << endl <<
            "Maksimal Penumpang\t: " << info(g).maksPenumpang << endl <<
            "Banyak Penumpang\t: "<< countPenumpangByGerbong(k, g)<<endl<<
            "Sisa Kursi\t\t: "<<info(g).sisaKursi<<endl<<
            "Konfigurasi Seat\t: " << info(g).konfigurasiSeat << endl <<
            "Harga Tiket\t\t: " << rupiah(info(g).hargaTiket) << endl << endl;
        } else {
            cout << "List gerbong kosong" << endl;
        }

        pause();
    }else if (inputUser == "11"){
        // Menampilkan Gerbong Dengan Jumlah Penumpang Paling Banyak
        adrGerbong g = maxPenumpang(k);
        if (g != NULL) {
            cout << "Gerbong dengan penumpang paling banyak adalah " << info(g).kelas << endl;
            cout <<
            "Kelas\t\t\t: " << info(g).kelas << endl <<
            "Maksimal Penumpang\t: " << info(g).maksPenumpang << endl <<
            "Banyak Penumpang\t: "<<countPenumpangByGerbong(k, g)<<endl<<
            "Sisa Kursi\t\t: "<<info(g).sisaKursi<<endl<<
            "Konfigurasi Seat\t: " << info(g).konfigurasiSeat << endl <<
            "Harga Tiket\t\t: " << rupiah(info(g).hargaTiket) << endl << endl;
        } else {
            cout << "List gerbong kosong" << endl;
        }
        pause();
    } else {
        invalidInput();
    }
    return inputUser;
}

void invalidInput() {
    /* {I.S.
        F.S. Procedure akan mencetak string} */
    cout << "Maaf input tidak valid."<<endl;
    pause();
}
