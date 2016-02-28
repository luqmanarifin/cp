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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int a[N], b[N];
LL atot, btot;

int main(void)
{
	int n, m, i, amax = -1, bmax = -1, apos, bpos;
	sf("%d %d", &n, &m);
	FORS(i, n) {
		sf("%d", a + i);
		atot += a[i];
		if(a[i] > amax) {
			amax = a[i];
			apos = i;
		}
	}
	FORS(i, m) {
		sf("%d", b + i);
		btot += b[i];
		if(b[i] > bmax) {
			bmax = b[i];
			bpos = i;
		}
	}
	LL aans = 0, bans = 0;
	FORS(i, n) {
		if(i == apos) {
			aans += btot;
			continue;
		}
		if(a[i] < btot) aans += a[i];
		else aans += btot;
	}
	FORS(i, m) {
		if(i == bpos) {
			bans += atot;
			continue;
		}
		if(b[i] < atot) bans += b[i];
		else bans += atot;
	}
	cout << min(aans, bans) << endl;
	return 0;
}
