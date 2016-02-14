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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

vector<int> prima;
bool isPrima[N];

int main(void)
{
	int i, j;
	reset(isPrima, 1);
	for(i = 2; i <= N - 5; ++i)
		if(isPrima[i]) {
			prima.push_back(i);
			if(1LL*i*i <= N - 5)
				for(j = i*i; j <= N - 5; j += i)
					isPrima[j] = 0;
		}
	int q; sf("%d", &q);
	while(q--) {
		int a;
		sf("%d", &a);
		pf("%d\n", prima[a-1]);
	}
	return 0;
}
