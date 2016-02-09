#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e6 + 5;

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) { return a*b / gcd(a, b); }

int Gcd(int a, int b) { return b? Gcd(b, a%b): a; }
int Lcm(int a, int b) { return a*b / Gcd(a, b); }

char x[N], y[N];
int xxx[N][26], yyy[N][26];
int sum[N];

int main(void)
{
	LL n, m, i, j;
	sf("%I64d %I64d", &n, &m);
	LL fpb = gcd(n, m);
	
	sf("%s %s", &x, &y);
	int xx = strlen(x);
	int yy = strlen(y);
	int Fpb = Gcd(xx, yy);
	FORS(i, xx) {
		xxx[i % Fpb][x[i]-'a']++;
	}
	FORS(i, yy) {
		yyy[i % Fpb][y[i]-'a']++;
		sum[i % Fpb]++;
	}
	
	LL ans = 0;
	FORS(i, Fpb)
		FORS(j, 26) {
			ans += 1LL*xxx[i][j]*(sum[i] - yyy[i][j]);
		}
	
	ans *= fpb;
	pf("%I64d\n", ans);
	
	return 0;
}
