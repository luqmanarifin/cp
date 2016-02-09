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
	char s[1005];
	gets(s);
	int n = strlen(s), i;
	FORS(i, n) {
		int now = s[i] - 'a';
		if(0 <= now && now <= 25)
			cur[now]++;
	}
	int ans = 0;
	FORS(i, 26)
		if(cur[i])
			ans++;
	cout << ans << endl;
	return 0;
}
