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

int main(void)
{
	int i, d, e, f;
	sf("%d %d %d", &d, &e, &f);
	FOR(i, 1, d) {
		if(d % i == 0) {
			int a = i;
			int b = d / i;
			if(e % b == 0) {
				int c = e / b;
				if(a * c == f) {
					cout << 4*(a + b + c) << endl;
					return 0;
				}
			}			
		}
	}
	
	return 0;
}
