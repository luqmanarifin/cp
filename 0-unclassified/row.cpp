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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, k, a[1010], i, ans = 1069, par;

int check(int b) {
	int base = a[b] - b*k;
	int temp = 0, j;
	FORS(j,n) if(a[j] != base + j*k) temp++;
	return temp;
}

int main()
{
	
	sf("%d %d", &n, &k);
	FORS(i,n) sf("%d", &a[i]);
	FORS(i,n) {
		if(a[i] - i*k <= 0) continue;
		int tmp = check(i);
		if(tmp < ans) {
			ans = tmp;
			par = i;
		}
	}
	int b = a[par] - par*k;
	pf("%d\n", ans);
	FORS(i,n) {
		if(b + i*k == a[i]) continue;
		if(b + i*k < a[i]) pf("- "); else pf("+ ");
		pf("%d %d\n", i+1, abs(b + i*k - a[i]));
	}
	return 0;
}