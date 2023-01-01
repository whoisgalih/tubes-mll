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
    cout << "12. Menghubungkan penumpang dan gerbong" << endl;
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
        if (searchGerbong(k,kelas)==NULL){
            maksPenumpang = intInput("Maksimal Penumpang\t: ");
            cout << "Konfigurasi seat\t: ";
            cin >> konfigurasiSeat;
            hargaTiket = intInput("Harga tiket\t\t: ");

            insertLastGerbong(k, createElmGerbong(createInfoGerbong(kelas, maksPenumpang, konfigurasiSeat, hargaTiket)));
        }else{
            cout << "Gerbong sudah ada" << endl;
        }
        pause();
    }else if (inputUser == "2"){
        infoPenumpang info;
        string kelas,nama,jenisKelamin;
        int nik,usia;

        cout << "Kelas Gerbong\t: ";
        getline(cin, kelas, '\n');
        getline(cin, kelas, '\n');

        adrGerbong srchGerbong = searchGerbong(k,kelas);
        if (srchGerbong!= NULL) {
            if (info(srchGerbong).sisaKursi>0){
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
                    connectPenumpangGerbong(k, "", nik, kelas);
                } else {
                    cout << "NIK sudah terdaftar" << endl;
                }
            }else{
                cout << "Maaf gerbong penuh" << endl;
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
                cout << "Terdapat penumpang dengan NIK " << nik << endl;
                cout << "Nama\t\t: " << info(p).nama << endl;
                cout << "Usia\t\t: " << info(p).usia << endl;
                cout << "Kategori \t: "<< info(p).kategori<<endl;
                cout << "Jenis kelamin\t: " << info(p).jenisKelamin << endl;
                cout << "Gerbong\t\t: " << info(gerbong(p)).kelas << endl;
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
            if (p){
                adrPenumpang g = k.penumpang.first;

                vector<vector<string>> t;
                t.push_back({"NIK","NAMA","USIA", "KATEGORI", "KELAMIN", "GERBONG"});

                while (g != NULL) {
                    if (toLower(info(g).nama )== toLower(nama)){
                        t.push_back({to_string(info(g).nik),info(g).nama,to_string(info(g).usia),info(g).kategori,info(g).jenisKelamin,info(gerbong(p)).kelas});
                    }
                    g = next(g);
                }

                table(t);
            }else {
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
        int nik;
        nik = intInput("Masukkan NIK: ");
        if (searchPenumpang(k, "", nik)){
            deletePenumpang(k,"", nik);
            pause();
        }else{
            cout << "Tidak terdapat penumpang dengan NIK "<<nik<<endl;
            pause();
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
        adrGerbong h = k.gerbong.first;

        if (g!=NULL) {
            cout << "Gerbong dengan penumpang paling sedikit adalah:  "<< endl;
            vector<vector<string>> t;
            t.push_back({"KELAS","JUMLAH PENUMPANG"});
            while (h != NULL) {
                if (info(h).sisaKursi == info(g).sisaKursi){
                    t.push_back({info(h).kelas,to_string(countPenumpangByGerbong(k,h))});
                }
                h = next(h);
            }
            table(t);
        } else {
            cout << "List gerbong kosong" << endl;
        }
        pause();
    }else if (inputUser == "11"){
        // Menampilkan Gerbong Dengan Jumlah Penumpang Paling Banyak
        adrGerbong g = maxPenumpang(k);
        adrGerbong h = k.gerbong.first;
        if (g != NULL) {
            cout << "Gerbong dengan penumpang paling banyak adalah:  "<< endl;
            vector<vector<string>> t;
            t.push_back({"KELAS","JUMLAH PENUMPANG"});
            while (h != NULL) {
                if (info(h).sisaKursi == info(g).sisaKursi){
                    t.push_back({info(h).kelas,to_string(countPenumpangByGerbong(k,h))});
                }
                h = next(h);
            }
            table(t);
        } else {
            cout << "List gerbong kosong" << endl;
        }
        pause();
    } else if (inputUser == "12") {
        string kelas;
        cout << "Kelas gerbong\t: ";
        getline(cin, kelas, '\n');
        getline(cin, kelas, '\n');

        int nik = intInput("NIK\t\t: ");

        connectPenumpangGerbong(k, "", nik, kelas);
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
