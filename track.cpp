#include <bits/stdc++.h>

using namespace std;

const long long inf = 4e18;

long long ver[305][305], hor[305][305], ver2[305][305], hor2[305][305];
int con[305][305];
tuple<int, int, int, int> ans;
long long dif, cur, a, b;

int main(void)
{	
	int n, m, t, i, j, k, l, r, mid, it;
	int eq, asc, des;
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &eq, &asc, &des);
	
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= m; j++) {
			scanf("%d", &con[i][j]);
			if(j > 1) {
				hor[i][j] = hor[i][j-1];
				hor2[i][j] = hor2[i][j-1];
				if(con[i][j] == con[i][j-1]) {
					hor[i][j] += eq;
					hor2[i][j] += eq;
				} else if(con[i][j-1] < con[i][j]) {
					hor[i][j] += asc;
					hor2[i][j] += des;
				} else {
					hor[i][j] += des;
					hor2[i][j] += asc;
				}
			}
			if(i > 1) {
				ver[i][j] = ver[i-1][j];
				ver2[i][j] = ver2[i-1][j];
				if(con[i][j] == con[i-1][j]) {
					ver[i][j] += eq;
					ver2[i][j] += eq;
				} else if(con[i-1][j] < con[i][j]) {
					ver[i][j] += asc;
					ver2[i][j] += des;
				} else {
					ver[i][j] += des;
					ver2[i][j] += asc;
				}
			}
		}
	}
	
	dif = inf;
	for(i = 1; i <= n - 2; i++) {
		for(j = 1; j <= m - 2; j++) {
			for(k = i + 2; k <= n; k++) {
				l = j + 2; r = m;
				while(l < r) {
					mid = (l + r + 1)/2;
					a = hor[i][mid] - hor[i][j] + hor2[k][mid] - hor2[k][j];
					b = ver2[k][j] - ver2[i][j] + ver[k][mid] - ver[i][mid];
					cur = a + b;
					if(cur < t) l = mid;
					else r = mid - 1;
				}
				
				for(it = l - 1; it <= l + 1; it++) {
					if(it < j + 2) continue;
					else if(m < it) break;
					a = hor[i][it] - hor[i][j] + hor2[k][it] - hor2[k][j];
					b = ver2[k][j] - ver2[i][j] + ver[k][it] - ver[i][it];
					cur = a + b;
					if(abs(cur - t) <= dif) {
						dif = abs(cur - t);
						ans = make_tuple(i, j, k, it);
						if(dif == 0) goto PRINT;
					}
				}
			}
		}
	} 
	
	PRINT:;
	tie(i, j, k, l) = ans;
	printf("%d %d %d %d\n", i, j, k, l);
	
	return 0;
}