#include "mll.h"

// MARK: - Inisialisasi Kereta Argo Parahyangan
kereta argoParahyangan()
{
    /* {Fungsi melakukan inisialisasi awal sebuah kereta,
        dan mengembalikan kereta yang list penumpang dan list gerbong nya sudah terisi} */

    // Create Info
    infoKereta info = createInfoKereta("Argo Parahyangan", "Stasiun Bandung (BD)", "Stasiun Gambir (GMR)", "Senin, 9 Januari 2023", "05:00", "07:45", 0, true);

    // Create Kereta
    kereta kereta = createKereta(info);

    // Dummy Data Gerbong Argo Parahyangan
    adrGerbong q;
    q = createElmGerbong(createInfoGerbong("Eksekutif-I 1", 50, "2-2", 170000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Eksekutif-I 2", 50, "2-2", 170000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-Q 1", 50, "2-2", 130000));
    insertLastGerbong(kereta, q);
    q = createElmGerbong(createInfoGerbong("Ekonomi-Q 2", 50, "2-2", 130000));
    insertLastGerbong(kereta, q);

    // Dummy Data Penumpang Argo Parahyangan
    adrPenumpang p;
    p = createElmPenumpang(createInfoPenumpang("Ilham Danial", 14, "Laki-laki"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Ilham Danial", "Eksekutif-I 1");

    p = createElmPenumpang(createInfoPenumpang("Alya Daud", 42, "Perempuan"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Alya Daud", "Eksekutif-I 1");

    p = createElmPenumpang(createInfoPenumpang("Muhammad Asis", 54, "Laki-laki"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Muhammad Asis", "Eksekutif-I 1");

    p = createElmPenumpang(createInfoPenumpang("Yohanes Umar", 59, "Laki-laki"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Yohanes Umar", "Eksekutif-I 2");

    p = createElmPenumpang(createInfoPenumpang("Ratu Mansur", 51, "Perempuan"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Ratu Mansur", "Eksekutif-I 2");

    p = createElmPenumpang(createInfoPenumpang("Surya Jamaludin", 68, "Laki-laki"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Surya Jamaludin", "Ekonomi-Q 1");

    p = createElmPenumpang(createInfoPenumpang("Mohamad Wangi", 70, "Laki-laki"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Mohamad Wangi", "Ekonomi-Q 1");

    p = createElmPenumpang(createInfoPenumpang("Ratu Mega", 16, "Perempuan"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Ratu Mega", "Ekonomi-Q 2");

    p = createElmPenumpang(createInfoPenumpang("Rahma Tirta", 60, "Perempuan"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Rahma Tirta", "Ekonomi-Q 1");

    p = createElmPenumpang(createInfoPenumpang("Rahma Sari", 39, "Perempuan"));
    insertLastPenumpang(kereta, p);
    connectPenumpangGerbong(kereta, "Rahma Sari", "Ekonomi-Q 2");

    // Return Kereta
    return kereta;
}
