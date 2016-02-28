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

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int a[100], i, sum = 0;
	FORS(i,100) {
		a[i] = rand() % 100;
		sum += a[i];
	}
	sort(a, a+100);
	pf("total : %d", sum); nl;
	pf("rata rata : %.6f", (DB)sum/100); nl;
	pf("median : %d %d", a[49], a[50]); nl;
	
	FORS(i,100) pf("%d ",a[i]); nl;
	
	while(true) {
		int standar; cin >> standar;
		int ans = 0;
		FORS(i,100)
			ans += abs(standar - a[i]);
		pf("%d", ans); nl; nl;
	}
	
	return 0;
}