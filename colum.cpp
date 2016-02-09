#include <bits/stdc++.h>

/**
 * Codeforces Round #283 (Div. 2)
 * Problem : C
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 105;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[N][N];
string cur[N][N][2];
int del[N][2];

int main(void)
{
	int n, m, i, j, k, a, b;
	FORS(i, N) FORS(j, 2) del[i][j] = inf;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) sf("%s", &s[i][1]);
	
	del[0][0] = 0;
	FOR(j, 1, m) {
		FORS(a, 2) FORS(b, 2) {
			if(del[j-1][a] + (!b) < del[j][b] && del[j-1][a] != inf) {
				bool valid = 1;
				FOR(i, 1, n) {
					cur[i][j][b] = cur[i][j-1][a];
					if(b) cur[i][j][b].push_back(s[i][j]);
					if(i > 1 && cur[i-1][j][b] > cur[i][j][b]) {
						valid = 0;
						break;
					}
				}
				if(valid) {
					del[j][b] = del[j-1][a] + (!b);
				}
			}
		}
	}
	//FOR(i, 1, n) pf("%s\n", cur[i][m][1].c_str());
	//pf("%d %d\n", del[n][0], del[n][1]);
	cout << min(m, min(del[n][0], del[n][1])) << endl;
	return 0;
}
