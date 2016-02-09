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
#define x first
#define y second

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[N], ans[N], pos[N], maxi[N];

bool by(int i, int j) {
	return a[i] < a[j];
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, i;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d", &a[i]);
		pos[i] = i;
	}
	sort(pos, pos + n, by);
	FORS(i,n) {
		maxi[i] = max(maxi[i-1], pos[i]);
	}
	
	int bef = -1;
	FORS(i, n) {
		if(a[pos[i]] != a[pos[i-1]])
			bef = i - 1;
		ans[pos[i]] = maxi[bef] - pos[i] - 1;
	}
	FORS(i,n)
		pf(ans[i] < 0? "-1 ":"%d ", ans[i]); nl;

	return 0;
}
