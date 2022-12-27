#include "mll.h"

// MARK: - Init kereta Turangga
kereta turangga(){
    /* {Fungsi melakukan inisialisasi awal sebuah kereta, dan mengembalikan kereta1 yang list penumpang dan list gerbong nya sudah terisi} */

    // CREATE INFO
    infoKereta info = createInfoKereta("Turangga", "Stasiun Bandung (BD)", "Stasiun Yogyakarta (YK)", "Senin, 9 Januari 2023", "18:40", "00:55",0,true);

    // CREATE KERETA
    kereta kereta1 = createKereta(info);

    // Dummy Gerbong Turangga
    adrGerbong q;
    q = createElmGerbong(createInfoGerbong("Eksekutif AA", 50, "2-2", 540000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif A", 50, "2-2", 510000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif H", 50, "2-2", 480000));
    insertLastGerbong(kereta1, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif I", 50, "2-2", 460000));
    insertLastGerbong(kereta1, q);

    // Dummy Penumpang Turangga
    adrPenumpang p;
    p = createElmPenumpang(createInfoPenumpang("Muhammad Abiya", 20, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Muhammad Abiya","Eksekutif AA");

    p = createElmPenumpang(createInfoPenumpang("Galih Akbar", 18, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Galih Akbar","Eksekutif A");

    p = createElmPenumpang(createInfoPenumpang("Gading Makruf", 17, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Gading Makruf","Eksekutif H");

    p = createElmPenumpang(createInfoPenumpang("Nada Raudah", 19, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Nada Raudah","Eksekutif I");

    p = createElmPenumpang(createInfoPenumpang("Dian Irdianingsih", 45, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Dian Irdianingsih","Eksekutif A");

    p = createElmPenumpang(createInfoPenumpang("Azumah Yasmin", 19, "Perempuang"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Azumah Yasmin","Eksekutif AA");

    p = createElmPenumpang(createInfoPenumpang("Falah Asyraf", 19, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Falah Asyraf","Eksekutif H");

    p = createElmPenumpang(createInfoPenumpang("Fajar Dwi", 5, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Fajar Dwi","Eksekutif H");

    p = createElmPenumpang(createInfoPenumpang("Makruf Amal", 55, "Laki-laki"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Makruf Amal","Eksekutif I");

    p = createElmPenumpang(createInfoPenumpang("Itoh Masitoh", 72, "Perempuan"));
    insertLastPenumpang(kereta1, p);
    connectPenumpangGerbong(kereta1,"Itoh Masitoh","Eksekutif AA");

    return kereta1;
}
