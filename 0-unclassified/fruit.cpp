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

int day[3005];

int main(void)
{
	int i, n, v;
	FORS(i, 3005) day[i] = 0;
	sf("%d %d", &n, &v);
	FORS(i, n) {
		int a, b;
		sf("%d %d", &a, &b);
		day[a] += b;
	}

	int ans = 0;
	FOR(i,1,3001) {
		int now = day[i] + day[i-1];
		int used = min(now, v);
		ans += used;
		int min1 = min(day[i-1], used);
		used -= min1;
		day[i-1] -= min1;
		day[i] -= used;
	}
	cout << ans << endl;
	
	return 0;
}
