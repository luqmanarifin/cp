#include <bits/stdc++.h>

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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int find(int a) {
	switch(a) {
		case 0 : return 2;
		case 1 : return 7;
		case 2 : return 2;
		case 3 : return 3;
		case 4 : return 3;
		case 5 : return 4;
		case 6 : return 2;
		case 7 : return 5;
		case 8 : return 1;
		case 9 : return 2;
	}
}

int main(void)
{
	int n;
	sf("%d", &n);
	cout << find(n / 10) * find(n % 10) << endl;
	return 0;
}
