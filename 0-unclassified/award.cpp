#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9+7;
const int maxn = 3e4 + 4;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int ans[maxn];
map<pair<int,int>, bool> ada;

int main(void)
{
	int i, n, m; sf("%d %d", &n, &m);
	while(m--) {
		int a, b;
		sf("%d %d", &a, &b);
		ada[mp(a,b)] = true;
	}
	
	FOR(i,1,n) {
		ans[i] = i;
		int j = i-1;
		while(ada[mp(ans[j], ans[j+1])]) {
			swap(ans[j], ans[j+1]);
			j--;
		}
	}
	
	FOR(i,1,n) pf("%d ", ans[i]); nl;
	
	return 0;
}
