#include <bits/stdc++.h>

/** 
 * Bayan 2015 Contest Warm Up
 * Problem : A
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

int n;

void pr(int a) {
	if(a <= n) pf("O");
	else pf("#");
	pf(".");
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	puts("+------------------------+");
	pf("|"); pr(1);
	for(i = 5; i <= 34; i += 3) pr(i);
	pf("|D|)"); nl;
	
	pf("|"); pr(2);
	for(i = 6; i <= 34; i += 3) pr(i);
	pf("|.|"); nl;
	
	pf("|"); pr(3);
	FORS(i, 10) pf(".."); pf("..|"); nl;
	
	pf("|"); pr(4);
	for(i = 7; i <= 34; i += 3) pr(i);
	pf("|.|)"); nl;
	
	
	puts("+------------------------+");
	
	return 0;
}
