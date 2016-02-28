#include <bits/stdc++.h>

/**
 * Nama	: Luqman Arifin Siswanto
 * NIM	: 13513024
 * Deskripsi : Membuat program kecil bertema database
 */

using namespace std;

struct siswa {
	char name[10];
	int kelas, n1, n2;
	bool stat;
};

siswa data[5];

bool valid(siswa s) {
	if(s.kelas < 10 || s.kelas > 12) return 0;
	if(s.n1 < 0 || s.n1 > 100 || s.n2 < 0 || s.n2 > 100) return 0;
	return 1;
}

void junk() {
	printf("Nama        Kelas  Nilai 1  Nilai 2  Kelulusan\n");
}

void space(int a) {
	for(int i = 0; i < a; i++) printf(" ");
}

int menuprint() {
	int ret;
	printf("=======================================\n");
	printf("Menu\n");
	printf("=======================================\n");
	printf("   1. Tampilkan Data Siswa\n");
	printf("   2. Cari data berdasarkan kelas\n");
	printf("   3. Cari data berdasarkan status kelulusan\n");
	printf("   4. Keluar\n");
	printf("\n");
	printf("Masukkan pilihan : ");
	scanf("%d", &ret);
	return ret;
}	

int main() {
	printf("=====================================\n");
	printf("    Database SMA Sinar Terang        \n");
	printf("=====================================\n");
	printf("=====================================\n");
	printf("Selamat datang\n");
	
	int i = 1;
	while(i <= 3) {
		printf("\nSilahkan masukkan data siswa ke-%d:\n", i);
		printf("Nama  : "); scanf("%s", data[i].name);
		printf("Kelas : "); scanf("%d", &data[i].kelas);
		printf("Nilai Ujian 1 : "); scanf("%d", &data[i].n1);
		printf("Nilai Ujian 2 : "); scanf("%d", &data[i].n2);
		if(valid(data[i])) {
			double mean = (1.0*data[i].n1 + 1.0*data[i].n2)/2;
			data[i].stat = (mean > 70);
			i++;
		} else {
			printf("Data siswa tidak valid, coba ulangi lagi\n\n");
		}
	}
	int menu = menuprint();
	while(menu != 4) {
		if(menu == 1) {
			printf("\n");
			junk();
			for(i = 1; i <= 3; i++) {
				printf("%s", data[i].name);
				space(13 - strlen(data[i].name));
				printf("%.2d", data[i].kelas);
				space(5);
				printf("%.2d", data[i].n1);
				space(8);
				printf("%.2d", data[i].n2);
				space(8);
				if(data[i].stat) puts("lulus");
				else puts("tidak");
			}
		} else if(menu == 2) {
			printf("Masukkan input yang dicari : ");
			int ret;
			scanf("%d", &ret);
			printf("\n");
			junk();
			for(i = 1; i <= 3; i++) {
				if(data[i].kelas == ret) {
					printf("%s", data[i].name);
					space(13 - strlen(data[i].name));
					printf("%.2d", data[i].kelas);
					space(5);
					printf("%.2d", data[i].n1);
					space(8);
					printf("%.2d", data[i].n2);
					space(8);
					if(data[i].stat) puts("lulus");
					else puts("tidak");
				}
			}
		} else if(menu == 3) {
			printf("Masukkan input yang dicari : ");
			char ret[10];
			bool ya = 0;
			scanf("%s", ret);
			if(ret[0] == 'y') ya = 1;
			for(i = 1; i <= 3; i++) {
				if(data[i].stat == ya) {
					printf("%s", data[i].name);
					space(13 - strlen(data[i].name));
					printf("%.2d", data[i].kelas);
					space(5);
					printf("%.2d", data[i].n1);
					space(8);
					printf("%.2d", data[i].n2);
					space(8);
					if(data[i].stat) puts("lulus");
					else puts("tidak");
				}
			}
		}
		menu = menuprint();
	}
	printf("\n");
	puts("Terima kasih");
	return 0;
}