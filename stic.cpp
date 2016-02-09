#include <bits/stdc++.h>

/** 
 * Bayan 2015 Contest Warm Up
 * Problem : 
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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool pat, lim, nam, due;
int cnt[10];

int main(void)
{
	int i, a;
	FORS(i, 6) {
		sf("%d", &a);
		cnt[a]++;
	}
	FOR(i, 1, 9) {
		if(cnt[i] == 6) nam = 1;
		if(cnt[i] == 5) lim = 1;
		if(cnt[i] == 4) pat = 1;
		if(cnt[i] == 2) due = 1;
	}
	if(nam || (pat && due)) puts("Elephant");
	else if(pat || lim) puts("Bear");
	else puts("Alien");
	
	return 0;
}
