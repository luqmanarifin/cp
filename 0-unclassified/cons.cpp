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
#define MINGGAT { puts("Impossible"); return 0; }

const LL mod = 1e9 + 7;


int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int node[3];

int main(void)
{
	int a, b, c;
	sf("%d %d %d", &a, &b, &c);
	node[0] = a; node[1] = b; node[2] = c;
	sort(node, node + 3);
	if(node[0] <= 0 || node[0] + node[1] <= node[2]) MINGGAT
	double teta = acos((DB)(1LL*a*a + 1LL*c*c - 1LL*b*b)/(2LL*a*c));
	double A = a;
	pf("0.0000000 0.0000000"); nl;
	pf("%.7lf 0.0000000", A); nl;
	pf("%.7lf %.7lf", c*cos(teta), c*sin(teta)); nl;
	
	return 0;
}
