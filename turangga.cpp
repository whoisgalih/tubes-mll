#include "mll.h"

kereta turangga(){
    /* {Fungsi melakukan inisialisasi awal sebuah kereta, dan mengembalikan kereta1 yang list penumpang dan list gerbong nya sudah terisi} */

    // CREATE INFO
    infoKereta info = createInfoKereta("Turangga", "Statsiun Bandung (BD)", "Statsiun Yogyakarta (YK)", "Senin, 9 Januari 2023", "18:40", "00:55",0);

    // CREATE KERETA
    kereta kereta1 = createKereta(info);

    // Dummy Penumpang Turangga
    adrPenumpang p;
    p = createElmPenumpang(createInfoPenumpang("Abiya", 20, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Galih", 18, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Gading", 17, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Nada", 19, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Dian", 45, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Azumah", 19, "Perempuang"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Falah", 19, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Fajar", 5, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Makruf", 55, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    p = createElmPenumpang(createInfoPenumpang("Itoh", 72, "Perempuan"));
    insertLastPenumpang(kereta1, p);

    // Dummy Gerbong Turangga
    adrGerbong q;
    q = createElmGerbong(createInfoGerbong("Eksekutif AA", 50, "2-2", 540.000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif A", 50, "2-2", 510.000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif H", 50, "2-2", 480.000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif I", 50, "2-2", 460.000));
    insertLastGerbong(kereta1, q);


    // CONNECT PENUMPANG DENGAN GERBONG
    connectPenumpangGerbong(kereta1,"Abiya","Eksekutif AA");
    return kereta1;
}
