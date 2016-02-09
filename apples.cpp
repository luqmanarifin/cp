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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> prime;
bitset<N> done, is;
vector<pair<int,int> > ans;

#define x first
#define y second

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	for(i = 2; i <= n/2; i++) {
		if(!is[i]) {
			prime.push_back(i);
			if(1LL*i*i <= n/2)
			for(j = i*i; j <= n/2; j += i)
				is[j] = 1;
		}
	}
	
	FORM(i, prime.size()) {
		vector<pair<int,int> > will;
		for(j = prime[i]*2; j <= n; j += prime[i])
			if(!done[j])
				will.push_back(mp(j & 1, j));
		sort(will.begin(), will.end());
		will.push_back(mp(1, prime[i]));
		for(j = will.size() - 1; j > 0; j -= 2) {
			if(!j) break;
			ans.push_back(mp(will[j].y, will[j-1].y));
			done[will[j].y] = 1;
			done[will[j-1].y] = 1;
		}
	}
	cout << ans.size() << endl;
	FORS(i, ans.size()) pf("%d %d\n", ans[i].x, ans[i].y);
	return 0;
}
