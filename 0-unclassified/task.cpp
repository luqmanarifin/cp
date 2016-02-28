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
const int N = 1e5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool done[26];

int main(void)
{
	LL ans = 1;
	char s[N];
	sf("%s", s);
	int now = 10, i, n = strlen(s), nol = 0;
	FORS(i, n) {
		if('0' <= s[i] && s[i] <= '9') continue;
		if(s[i] == '?') (i? nol++ : ans *= 9);
		else if(!done[s[i]-'A'])
			done[s[i]-'A'] = 1, ans *= 1LL*(i? now : 9), now--;
	}
	pf("%I64d", ans);
	FORS(i, nol) pf("0"); nl;
	return 0;
}
