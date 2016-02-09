#include <bits/stdc++.h>

/**
 * Codeforces Round #262 (Div. 2)
 * Problem : C
 * Luqman Arifin (kadalbonek)
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
const int N = 2e5 + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL a[N], tumbuh[N];

int main(void)
{
	int n, m, w, i, j;
	sf("%d %d %d", &n, &m, &w);
	FOR(i, 1, n) sf("%d", a + i);
	LL l = 1, r = 1e10;
	while(l < r) {
		LL mid = (l + r + 1) >> 1;
		LL add = 0, need = 0;
		reset(tumbuh, 0);
		FOR(i, 1, n) {
			add += tumbuh[i];
			if(a[i] + add < mid) {
				LL dif = mid - a[i] - add;
				add += dif;
				tumbuh[i + w] -= dif;
				need += dif;
			}
		}
		if(need > m) r = mid - 1;
		else l = mid;
	}
	cout << l << endl;
	return 0;
}
