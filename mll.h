#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

#include <cstdlib>

#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define gerbong(P) (P)->gerbong

// MARK: - Gerbong
struct infoGerbong{
    string kelas;
    int maksPenumpang;
    string konfigurasiSeat;
    int hargaTiket;
};

typedef struct infoGerbong infotypeGerbong;
typedef struct elmGerbong *adrGerbong;

struct elmGerbong{
    infotypeGerbong info;
    adrGerbong next;
    adrGerbong prev;
};

struct listGerbong{
    adrGerbong first;
    adrGerbong last;
};

// MARK: - Penumpang
struct infoPenumpang{
    string nama;
    int usia;
    string jenisKelamin;
};

typedef struct infoPenumpang infotypePenumpang;
typedef struct elmPenumpang *adrPenumpang;

struct elmPenumpang{
    infotypePenumpang info;
    adrPenumpang next;
    adrPenumpang prev;
    adrGerbong gerbong;

};

struct listPenumpang{
    adrPenumpang first;
    adrPenumpang last;
};


// MARK: - Kereta
struct infoKereta {
    string nama, asal, tujuan, tanggal, jamBerangkat, jamTiba;
    int panjangRangkaian;
};

struct kereta {
    listGerbong gerbong;
    listPenumpang penumpang;
    infoKereta info;
};


// MARK: - Function/Procedure Penumpang
listPenumpang createListPenumpang();
infotypePenumpang createInfoPenumpang(string nama, int usia, string jenisKelamin);
adrPenumpang createElmPenumpang(infotypePenumpang X);
void insertLastPenumpang(kereta &k, adrPenumpang P); //FUNGSIONALITAS DASAR A
void showPenumpang(kereta k); //FUNGSIONALITAS DASAR C
adrPenumpang searchPenumpang(kereta k, string nama); //FUNGSIONALITAS DASAR B
void deletePenumpang(kereta &k, string nama);
void showPenumpangByGerbong(kereta k, adrGerbong g); //FUNGSIONALITAS DASAR F
int countPenumpangByGerbong(kereta k, adrGerbong g); //FUNGSIONALITAS DASAR G

// MARK: - Function/Procedure Gerbong
listGerbong createListGerbong();
infotypeGerbong createInfoGerbong(string kelas, int maksPenumpang, string konfigurasiSeat, int hargaTiket);
adrGerbong createElmGerbong(infotypeGerbong X);
void insertLastGerbong(kereta &k, adrGerbong P); //FUNGSIONALITAS DASAR A
void showGerbong(kereta k); //FUNGSIONALITAS DASAR C
adrGerbong searchGerbong(kereta k, string kelas); //FUNGSIONALITAS DASAR B
void deleteGerbong(kereta &k, adrGerbong g); //FUNGSIONALITAS DASAR E
int countGerbong(kereta k);

// MARK: - Function/Procedure Kereta
kereta createKereta(infoKereta info);
infoKereta createInfoKereta(string nama, string asal, string tujuan, string tanggal, string jamBerangkat, string jamTiba, int panjangRangkaian);
void connectPenumpangGerbong(kereta &k, string nama, string kelas); //FUNGSIONALITAS DASAR D
void showKereta(kereta k);
int countPenumpang(kereta k);
void deleteDisconnectGerbong(kereta &k, string kelas); //FUNGSIONALITAS DASAR E
adrGerbong maxPenumpang(kereta k); //FUNGSIONALITAS DASAR H
adrGerbong minPenumpang(kereta k); //FUNGSIONALITAS DASAR I

// MARK: - Inisialisasi
kereta turangga();

// MARK: - Table
void tableHorizontalSparator(int col, int colWidth[]);
void tableRow(int col, int colWidth[], string data[]);

// MARK: - Menu
string menu();
string menuLokal();
string menuAntarKota();
string menuKereta(kereta &k);
void invalidInput();

// MARK: - Utils
void clearScreen();
void pause();
string rupiah(int i);

#endif // MLL_H_INCLUDED
