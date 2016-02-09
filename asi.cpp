#include <bits/stdc++.h>

/**
 * Nama	: Luqman Arifin Siswanto
 * NIM	: 13513024
 * Deskripsi : Membuat program kecil untuk bermain bentuk
 */

using namespace std;

void space(int a) {
	for(int i = 0; i < a; i++)
		printf(" ");
}

void bintang(int a) {
	for(int i = 0; i < a; i++)
		printf("*");
}

int main () {
	int i, j, n;
	printf("=================================\n");
	printf("     Program Kreasi Bentuk       \n");
	printf("=================================\n");
	printf("\n");
	printf("Masukkan sebuah nilai : "); scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		space(n - i);
		for(j = 1; j <= i; j++)
			printf("%d", j);
		for(j = i-1; j >= 1; j--)
			printf("%d", j);
		printf("\n");
	}
	printf("\n");
	printf("=================================\n");
	
	int a, b;
	printf("Masukkan tinggi   : "); scanf("%d", &a);
	printf("Masukkan panjang  : "); scanf("%d", &b);
	bintang(b); printf("\n");
	for(i = 0; i < a - 2; i++) {
		printf("*");
		space(b-2);
		printf("*\n");
	}
	bintang(b); printf("\n");
	printf("\n");
	printf("=================================\n");
	
	for(j = 0; j < 2; j++) {
		for(i = 5; i <= 10; i++) {
			bintang(i);
			space(10);
			bintang(15-i);
			printf("\n");
		}
		for(i = 9; i >= 6; i--) {
			bintang(i);
			space(10);
			bintang(15-i);
			printf("\n");
		}
	}
	printf("\n");
	
	return 0;
}