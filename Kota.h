#ifndef KOTA_H
#define KOTA_H

#include "linked.h"

#define MAX_KOTA 5  // batas maksimum untuk jumlah kota yang disimpan nya 5

typedef struct {
    char namaKota[50];  // nama kota
    LinkedList daftarNama;  // linked list buat nyimpen nama nama orang di kota 
} Kota;

// fungsi
void inisialisasiKota(Kota daftarKota[], int *jumlahKota); // inisisalisasi array kota dan jumlah kota
void tambahKota(Kota daftarKota[], int *jumlahKota, char nama[]); // menambahkan kota ke array kota
void hapusKota(Kota daftarKota[], int *jumlahKota, char nama[]); // menghapus kota dari array
void tampilkanDataSemuaKota(Kota daftarKota[], int jumlahKota); // menampilkan semua kota dan daftar nama
void tampilkanDataPerKota(Kota daftarKota[], int jumlahKota, char nama[]); // menampilkan daftar nama dari kota tertentu
int cariIndexKota(Kota daftarKota[], int jumlahKota, char nama[]);  // mencari index kota berdasarkan namanya

#endif
