#include <bits/stdc++.h>

/**
 * Competitive Programming Final CP Mahasiswa
 * Problem : D | Memotong Kue
 * Gajah Wangi (ITB)
 **/

typedef long long LL;
typedef double db;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")
#define FOR(i, a, b) for(i = a; i <= b; i++)
#define FORD(i, a, b) for(i = a; i >= b; i--)
#define FORS(i, n) for(i = 0; i < n; i++)
#define FORM(i, n) for(i = n - 1; i >= 0; i--)
#define reset(i, n) memset(i, n, sizeof(i))
#define open freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

int main() {
	int t, n, i, p, q, r, res, x;
	sf("%d", &t);
	while(t--) {
		sf("%d", &n);
		n++;
		if(n & 1) {
			res = 3*n*n - 3*n + 1;
		} else {
			res = 3*n*n - 6*n + 6;
		}
		x = n/2 - 1;
		FOR(p, 1, x) FOR(q, 1, x) {
			int lef = 1, rig = x;
			while(lef < rig) {
				int mid = (lef + rig) >> 1;
				if(1LL*(n - q)*p*mid < 1LL*q*(n - p)*(n - mid))
					lef = mid + 1;
				else rig = mid;
			}
			if(1LL*(n - q)*p*lef == 1LL*q*(n - p)*(n - rig))
				res -= 6;
		}
		pf("%d\n", res);
	}
	
	return 0;
}