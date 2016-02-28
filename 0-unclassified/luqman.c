#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>
#include <stdlib.h>

#define false 0
#define true 1

static const double eps = 1e-13;

/* Mengembalikan true bila a == b */
bool Equal(double a, double b) {
	return abs(a - b) < eps;
}

/* Tukar dua nilai double / swap */
void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

int n, i, j;
double m[100][200];


/* **** TAMBAHAN AJA **** */
/* Menukar baris ke-i ke-j dengan i, j terdefinisi untuk matriks m*/
void TukarBaris(int i, int j) {
	int k;
	for(k = 0; k < n; k++)
		swap(&m[i][k], &m[j][k]);
}

/* Operasi baris ke-i ditambah baris ke-j dikali c */
void Operasi(int i, double c, int j) {
	int k;
	for(k = 0; k < n; k++) {
		m[i][k] -= c*m[j][k];
	}
}

/* Operasi baris ke-i dikali dengan konstanta c */
void KaliBaris(int i, double c) {
	int k;
	for(k = 0; k < n; k++) {
		m[i][k] *= c;
	}
}

/*	Prekondisi: IsBujurSangkar(M)
 * Menghitung nilai determinan M */
double Determinan() {
	double ret[100][200];

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			ret[i][j] = m[i][j];
	
	double det = 1;
	if(Equal(ret[0][0], 0.0)) {
		bool done = false;
		for(i = 1; i < n; i++) {
			if(!Equal(ret[i][0], 0)) {
				TukarBaris(0, i);
				det *= -1;
				done = true;
				break;
			}
		}
		if(!done) return 0.0;
	}
	
	/* Gaussian Algorithm */
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			if(i < j) continue;
			if(i == j) {
				if(Equal(ret[i][j], 0)) continue;
				if(!Equal(ret[i][j], 1)) {
					det *= ret[i][j];
					KaliBaris(i, 1.0/ret[i][j]);
				}
			} else {
				if(!Equal(ret[i][j], 0)) {
					Operasi(i, ret[i][j], j);
				}
			}
		}

	return det;
}



/*	Menghasilkan salinan M dg setiap elemen "di-invers", yaitu di-invers
 * sesuai dengan aturan inversi matriks */
int main() {
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			scanf("%lf", &m[i][j]);
		}
		m[i][i + n] = 1.0;
	}

	/* Gaussian Algorithm (from Geometry Algebra Course) */
	for(i = 0; i < n; i++)
		for(j = 0; j < 2*n; j++) {
			if(i < j) continue;
			if(i == j) {
				if(!Equal(m[i][j], 1))
					KaliBaris(i, 1.0/m[i][j]);
			} else {
				if(!Equal(m[i][j], 0)) {
					Operasi(i, m[i][j], j);
				}
			}
		}

	for(i = 0; i < n; i++)
		for(j = 0; j < 2*n; j++) {
			if(i >= j || j >= n) continue;
			if(!Equal(m[i][j], 0))
				Operasi(i, m[i][j], j);
		}

	for(i = 0; i < n; i++) {
		for(j = 0; j < 2*n; j++)
			printf("%.3lf ", m[i][j]);
		printf("\n");
	}

	return 0;
}
