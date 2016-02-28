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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int cur[26];

int main(void)
{
	int n, i;
	sf("%d", &n);
	FORS(i, n) {
		char s[105];
		bool done[26];
		reset(done, 0);
		sf("%s", s);
		int m = strlen(s), j;
		FORS(j, m) {
			int c = s[j] - 'a';
			if(!done[c]) {
				cur[c]++;
				done[c] = 1;
			}
		}
	}
	int ans = 0;
	FORS(i, 26)
		if(cur[i] == n)
			ans++;
	cout << ans << endl;
	return 0;
}
