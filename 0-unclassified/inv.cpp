#include <bits/stdc++.h>

/**
 * Codeforces Round #270
 * Problem : D
 * Luqman A. Siswanto (kadalbonek)
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL dist[2005][2005];

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	FORS(i, n) FORS(j, n) sf("%d", &dist[i][j]);
	FORS(i, n) FORS(j, n) {
		if(i == j) {
			if(dist[i][j]) {
				puts("NO");
				return 0;
			}
		} else {
			if(dist[i][j] != dist[j][i] || dist[i][j] == 0) {
				puts("NO");
				return 0;
			}
		}
	}
	LL cnt = 0;
	int mid;
	FORS(mid, n) FORS(i, n) FORS(j, n) {
		if(dist[i][mid] + dist[mid][j] == dist[i][j])
			cnt++;
	}
	cout << cnt << endl;
	puts(cnt == 2*n*n - 1? "YES" : "NO");
	return 0;
}
