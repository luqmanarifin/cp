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
const int N = 25005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[N];
int front[N], back[N];

int main(void)
{
	int i, j, n;
	sf("%s", &s[1]);
	n = strlen(&s[1]);
	FOR(i, 1, n) {
		if(s[i] == '2') {
			front[i]++;
			back[i]++;
		}
	}
	FOR(i, 1, n) front[i] += front[i-1];
	FORD(i, n, 1) back[i] += back[i+1];
	LL ansa = 0, ansb = 0;
	FOR(i, 1, n) {
		if(s[i] == '1') {
			ansa += front[i];
			ansb += back[i];
		}
	}
	cout << min(ansa, ansb) << endl;
	return 0;
}
