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

const LL mod = 1e9 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	int t; sf("%d", &t);
	int num[100005];
	while(t--) {
		reset(num, 0);
		int n, i; sf("%d", &n);
		FORS(i, n) sf("%d", &num[i]);
		sort(num, num+n);
		FORS(i,n) if(i%2 && i != n-1) swap(num[i], num[i+1]);
		FORS(i,n) pf("%d ", num[i]); nl;
	}
	
	return 0;
}
