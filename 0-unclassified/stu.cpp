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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int x, y, c[105];

bool valid(int a) {
	return (x <= a && a <= y);
}

int main(void)
{
	int m, i;
	sf("%d", &m);
	FORS(i, m) {
		sf("%d", c + i);
		c[i] += c[i-1];
	}
	sf("%d %d", &x, &y);
	FORS(i, m)
		if(valid(c[i]) && valid(c[m-1] - c[i])) {
			pf("%d\n", i + 2);
			return 0;
		}

	puts("0");
	return 0;
}
