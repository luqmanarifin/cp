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

int main(void)
{
	int n;
	sf("%d", &n);
	switch (n) {
		case 1 : puts("0"); break;
		case 2 : puts("72"); break;
		case 3 : puts("801"); break;
		case 4 : puts("8811"); break;
		case 5 : puts("89001"); break;
		case 6 : puts("898101"); break;
		case 7 : puts("8990001"); break;
		case 8 : puts("89981001"); break;
		case 9 : puts("899900001"); break;
		case 10 : puts("8999810001"); break;
	}
	return 0;
}
