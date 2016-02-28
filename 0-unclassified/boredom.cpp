#include <bits/stdc++.h>

/**
 * Codeforces Round #260 (Div. 2)
 * Problem : C
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
const int N = 1e5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int cnt[N + 5], l, r;
LL ans;
bool done[N + 5];
vector<pair<int,int> > seg;
vector<pair<LL, int> > will;

LL sum(int i) {
	return 1LL*i*cnt[i];
}

LL solve(int pos) {
	if(done[pos]) return 0;
	LL samping = 0;
	if(l <= pos-1 && !done[pos-1]) samping += sum(pos-1);
	if(pos+1 <= r && !done[pos+1]) samping += sum(pos+1);
	if(sum(pos) > samping) {
		ans += sum(pos);
		done[pos] = 1;
		done[pos+1] = 1;
		done[pos-1] = 1;
	}
	LL ret = 0;
	if(l <= pos - 1) ret += solve(pos - 1);
	if(r >= pos + 1) ret += solve(pos + 1);
	return ret;
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) {
		int x;
		sf("%d", &x);
		cnt[x]++;
	}
	for(i = 1; i <= N; i = r) {
		r = i + 1;
		if(cnt[i]) {
			while(cnt[r] || N < r) r++;
			seg.push_back(mp(i, r-1));
		}
	}
	
	FORS(i, seg.size()) {
		will.clear();
		l = seg[i].first; r = seg[i].second;
		FOR(j, l, r)
			will.push_back(mp(sum(j), j));
		sort(will.begin(), will.end());
		reverse(will.begin(), will.end());
		FORS(j, will.size()) {
			ans += solve(will[j].second);
			done[will[j].second] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}
