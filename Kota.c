#include "kota.h"

void inisialisasiKota(Kota daftarKota[], int *jumlahKota) {
    *jumlahKota = 0;
}

void tambahKota(Kota daftarKota[], int *jumlahKota, char nama[]) {
    if (*jumlahKota >= MAX_KOTA) {
        printf("Kapasitas kota sudah maksimal!\n");
        return;
    }
    strcpy(daftarKota[*jumlahKota].namaKota, nama);
    createList(&daftarKota[*jumlahKota].daftarNama);
    (*jumlahKota)++;
}

void hapusKota(Kota daftarKota[], int *jumlahKota, char nama[]) {
    int index = cariIndexKota(daftarKota, *jumlahKota, nama);
    if (index == -1) {
        printf("Kota tidak ditemukan.\n");
        return;
    }

    // menghapus seluruh nama pada linked list kota tersebut
    while (daftarKota[index].daftarNama.head != NULL) {
        deleteFirst(&daftarKota[index].daftarNama);
    }

    // Geser array kota untuk menutupi yang dihapus
    for (int i = index; i < *jumlahKota - 1; i++) {
        daftarKota[i] = daftarKota[i + 1];
    }
    (*jumlahKota)--;
}

int cariIndexKota(Kota daftarKota[], int jumlahKota, char nama[]) {
    for (int i = 0; i < jumlahKota; i++) {
        if (strcmp(daftarKota[i].namaKota, nama) == 0) {
            return i;
        }
    }
    return -1;
}

void tampilkanDataSemuaKota(Kota daftarKota[], int jumlahKota) {
    for (int i = 0; i < jumlahKota; i++) {
        printf("Kota: %s\n", daftarKota[i].namaKota);
        printList(daftarKota[i].daftarNama);
        printf("\n");
    }
}

void tampilkanDataPerKota(Kota daftarKota[], int jumlahKota, char nama[]) {
    int index = cariIndexKota(daftarKota, jumlahKota, nama);
    if (index != -1) {
        printf("Kota: %s\n", daftarKota[index].namaKota);
        printList(daftarKota[index].daftarNama);
    } else {
        printf("Kota tidak ditemukan.\n");
    }
}
