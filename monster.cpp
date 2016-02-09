#include <bits/stdc++.h>

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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int hy, ay, dy;
int hm, am, dm;
int hp, atk, def;

bool win(int a, int b, int c) {
	int musuh = max(0, b - dm);
	int kita = max(0, am - c);
	if(musuh == 0) return 0;
	int kali = hm / musuh;
	if(hm % musuh) kali++;
	a -= kali*kita;
	return (a > 0);
}

int main(void)
{
	int i, j, k, ans = inf;
	sf("%d %d %d", &hy, &ay, &dy);
	sf("%d %d %d", &hm, &am, &dm);
	sf("%d %d %d", &hp, &atk, &def);
	FOR(i, 0, 100) FOR(j, 0, 100) FOR(k, 0, 100) {
		if(win(hy + i, ay + j, dy + k)) {
			ans = min(ans, i*hp + j*ay + k*dy);
		}	
	}
	cout << ans << endl;
	return 0;
}
