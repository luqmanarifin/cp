#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

double M[100][200];
int i, j, k, n;

int main(void) {
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			scanf("%lf", &M[i][j]);
		}
		M[i][n + i] = 1.0;
	}

	for (i = 0; i < n; ++i) {
		if (!islessgreater(M[i][i], 0.0)) {
			bool got = 0;
			j = i + 1;
			while (j < n && !got) {
				if (islessgreater(M[j][i], 0.0)) {
					/* Swap baris i dan j */
					for (k = 0; k < 2 * n; ++k) {
						double tmp = M[i][k];
						M[i][k] = M[j][k];
						M[j][k] = tmp;
					}
					got = 1;
				}
				++j;
			}
			if(!got) {
				puts("Invers tidak ada. Determinan matriks = 0.");
				return 0;
			}
		}

		if (islessgreater(M[i][i], 0.0)) {
			double factor = 1.0 / M[i][i];
			for (j = 0; j < 2 * n; ++j) {
				M[i][j] *= factor;
			}
			for (j = 0; j < n; ++j)
			if (j != i) {
				factor = - M[j][i] / M[i][i];
				for (k = 0; k < 2 * n; ++k) {
					M[j][k] += (M[i][k] * factor);
				}
			}
		}
	}

	for (i = 0; i < n; ++i) {
		for (j = n; j < 2 * n; ++j) {
			printf("%.4lf ", M[i][j]);
		}
		puts("");
	}
	return 0;
}
