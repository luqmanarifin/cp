#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl cout << '\n'

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n;
string s[5], perm[5], tc[25];

int findx() {
	int dif = 0, i, j;
	string tmp[5];
	FORS(i, n) tmp[i] = perm[i];
	FORS(i, n)
		FORD(j, n-1, i+1)
			if(s[i] == tmp[j]) {
				dif++;
				swap(tmp[j-1], tmp[j]);
			}
	return dif;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int p = 0, i, j, ans, q, k;
	cin >> n;
	FORS(i, n) cin >> s[i];
	cin >> q;
	FOR(i, 1, q) {
		cin >> k;
		FORS(j, k) cin >> tc[j];
		FORS(j, n) perm[j] = s[j];
		int fact = 1;
		FOR(j, 1, n) fact *= j;
		while(fact--) {
			int x = findx(), now = 0;
			FORS(j, k)
				if(tc[j] == perm[now])
					now++;
			if(now == n) {
				int cur = n*(n - 1)/2 - x + 1;
				if(cur > p) {
					p = cur;
					ans = i;
				}
			}
			next_permutation(perm, perm + n);
		}
	}
	if(p) {
		cout << ans << endl;
		pf("[:"); FORS(i, p) pf("|"); pf(":]\n");
	} else
		puts("Brand new problem!");
	return 0;
}
