#include <bits/stdc++.h>

/**
 * Codeforces Round #263 (Div. 2)
 * Problem : B
 * Luqman Arifin (kadalbonek)
 */

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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[N];
int cnt[26];

int main(void)
{
	int n, k, i, j;
	sf("%d %d %s", &n, &k, s);
	int len = strlen(s);
	FORS(i, len) cnt[s[i]-'A']++;
	sort(cnt, cnt + 26);
	reverse(cnt, cnt + 26);
	LL ans = 0;
	//FORS(i, 26) pf("%d ", cnt[i]); nl;
	FORS(i, 26) {
		if(k <= 0) break;
		ans += 1LL*min(k, cnt[i])*min(k, cnt[i]);
		k -= min(k, cnt[i]);
	}
	cout << ans << endl;
	return 0;
}
