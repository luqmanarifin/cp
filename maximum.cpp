#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9+7;
const int maxn = 2e5+5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int num[maxn], fre[maxn];
LL occ[maxn];

int main(void)
{
	int n, q, i; sf("%d %d", &n, &q);
	FORS(i,n) sf("%d", num + i);
	
	reset(fre, 0);
	while(q--) {
		int a, b;
		sf("%d %d", &a, &b);
		a--; b--;
		fre[a]++;
		fre[b+1]--;
	}
	
	reset(occ, 0);
	LL cho = 0;
	FORS(i,n) {
		cho += fre[i];
		occ[i] = cho;
	}
	
	sort(num, num+n);
	sort(occ, occ+n);
	
	LL ans = 0;
	FORS(i,n) ans += 1LL*num[i]*occ[i];
	cout << ans << endl;
	
	return 0;
}