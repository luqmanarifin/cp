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
string cur[N], temp[N];

int main(void)
{
	int n, m, i, j, k, a, b;
	sf("%d %d", &n, &m);
	FORS(i, n) sf("%s", s[i]);
	int ans = 0;
	FORS(j, m) {
		FORS(i, n) {
			temp[i] = cur[i];
			cur[i].push_back(s[i][j]);
		}
		bool valid = 1;
		FOR(i, 1, n-1) {
			if(cur[i-1] > cur[i]) {
				valid = 0;
				break;
			}
		}
		if(!valid) {
			ans++;
			FORS(i, n) cur[i] = temp[i];
		}
	}
	cout << ans << endl;
	return 0;
}
