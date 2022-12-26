#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED

#include <iostream>
using namespace std;

#include <sstream>

#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info
#define gerbong(P) (P)->gerbong

//GERBONG
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

//PENUMPANG
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


//KERETA
struct infoKereta {
    string nama, asal, tujuan, tanggal, jamBerangkat, jamTiba;
    int panjangRangkaian;
};

struct kereta {
    listGerbong gerbong;
    listPenumpang penumpang;
    infoKereta info;
};


// FUNCTION/PROCEDURE PENUMPANG
listPenumpang createListPenumpang();
infotypePenumpang createInfoPenumpang(string nama, int usia, string jenisKelamin);
adrPenumpang createElmPenumpang(infotypePenumpang X);
void insertLastPenumpang(kereta &k, adrPenumpang P); //FUNGSIONALITAS DASAR A
void showPenumpang(kereta k); //FUNGSIONALITAS DASAR C
adrPenumpang searchPenumpang(kereta k, string nama); //FUNGSIONALITAS DASAR B
void deletePenumpang(kereta &k, string nama);
void showPenumpangByGerbong(kereta k, string kelas); //FUNGSIONALITAS DASAR F
int countPenumpangByGerbong(kereta k,string kelas); //FUNGSIONALITAS DASAR G

// FUNCTION/PROCEDURE GERBONG
listGerbong createListGerbong();
infotypeGerbong createInfoGerbong(string kelas, int maksPenumpang, string konfigurasiSeat, int hargaTiket);
adrGerbong createElmGerbong(infotypeGerbong X);
void insertLastGerbong(kereta &k, adrGerbong P); //FUNGSIONALITAS DASAR A
void showGerbong(kereta k); //FUNGSIONALITAS DASAR C
adrGerbong searchGerbong(kereta k, string kelas); //FUNGSIONALITAS DASAR B
void deleteGerbong(kereta &k, string kelas); //FUNGSIONALITAS DASAR E
int countGerbong(kereta k);

// FUNCTION/PROCEDURE KERETA
kereta createKereta(infoKereta info);
infoKereta createInfoKereta(string nama, string asal, string tujuan, string tanggal, string jamBerangkat, string jamTiba, int panjangRangkaian);
void connectPenumpangGerbong(kereta &k, string nama, string kelas); //FUNGSIONALITAS DASAR D
void showKereta(kereta k);
int countPenumpang(kereta k);
void deleteDisconnectGerbong(kereta &k, string kelas); //FUNGSIONALITAS DASAR E
adrGerbong maxPenumpang(kereta k); //FUNGSIONALITAS DASAR H
adrGerbong minPenumpang(kereta k); //FUNGSIONALITAS DASAR I

// INISIALISASI
kereta turangga();

// table
void tableHorizontalSparator(int col, int colWidth[]);
void tableRow(int col, int colWidth[], string data[]);

// MENU
int menu();
int menuLokal();
int menuAntarKota();
int menuKereta(kereta &k);

#endif // MLL_H_INCLUDED
