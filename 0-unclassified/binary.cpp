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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int main(void)
{
	char s[N];
	sf("%s", s);
	int i, n = strlen(s), cur = 0;
	bool ada = 0; int ans = 0;
	FORD(i, n-1, 1) {
		if(s[i] == '1' && !ada) ada = 1;
		if(s[i] == '1')
			cur++;
		else {
			ans += ada + cur + 1;
			cur = 0;
		}
	}
	if(ada) ans += ada + cur + 1;
	pf("%d\n", ans);
	return 0;
}
