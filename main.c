#include <stdio.h>
#include <stdlib.h>
#include "kota.h"

int main() {
    Kota daftarKota[MAX_KOTA];
    int jumlahKota;
    inisialisasiKota(daftarKota, &jumlahKota);

    int pilihan;
    char namaKota[50];
    char namaOrang[50];

    do {
        printf("\n=== MENU ===\n");
        printf("1. Tambah Kota\n");
        printf("2. Hapus Kota\n");
        printf("3. Tambah Nama ke Kota\n");
        printf("4. Hapus Nama dari Kota\n");
        printf("5. Tampilkan Semua Kota & Data\n");
        printf("6. Tampilkan Data per Kota\n");
        printf("0. Keluar\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        getchar(); // menangani newline

        switch (pilihan) {
            case 1:
                printf("Masukkan nama kota baru: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0'; // hapus newline
                tambahKota(daftarKota, &jumlahKota, namaKota);
                break;

            case 2:
                printf("Masukkan nama kota yang akan dihapus: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                hapusKota(daftarKota, &jumlahKota, namaKota);
                break;

            case 3:
                printf("Masukkan nama kota tujuan: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                printf("Masukkan nama yang akan ditambahkan: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';
                {
                    int idx = cariIndexKota(daftarKota, jumlahKota, namaKota);
                    if (idx != -1) {
                        insertLast(&daftarKota[idx].daftarNama, namaOrang);
                    } else {
                        printf("Kota tidak ditemukan!\n");
                    }
                }
                break;

            case 4:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                printf("Masukkan nama yang akan dihapus: ");
                fgets(namaOrang, sizeof(namaOrang), stdin);
                namaOrang[strcspn(namaOrang, "\n")] = '\0';
                {
                    int idx = cariIndexKota(daftarKota, jumlahKota, namaKota);
                    if (idx != -1) {
                        deleteValue(&daftarKota[idx].daftarNama, namaOrang);
                    } else {
                        printf("Kota tidak ditemukan!\n");
                    }
                }
                break;

            case 5:
                tampilkanDataSemuaKota(daftarKota, jumlahKota);
                break;

            case 6:
                printf("Masukkan nama kota: ");
                fgets(namaKota, sizeof(namaKota), stdin);
                namaKota[strcspn(namaKota, "\n")] = '\0';
                tampilkanDataPerKota(daftarKota, jumlahKota, namaKota);
                break;

            case 0:
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }
    } while (pilihan != 0);

    return 0;
}
