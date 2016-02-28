#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = (1 << 17);

priority_queue<pair<int,int>> pq;
vector<pair<int,int>> ans;
int deg[N], s[N];

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) {
		sf("%d %d", &deg[i], &s[i]);
		pq.emplace(-deg[i], i);
	}
	while(!pq.empty()) {
		int cur, id;
		tie(cur, id) = pq.top();
		pq.pop();
		cur = -cur;
		if(deg[id] != cur || cur == 0) continue;
		int near = s[id];
		ans.emplace_back(id, near);
		deg[near]--;
		s[near] ^= id;
		pq.emplace(-deg[near], near);
	}
	random_shuffle(ans.begin(), ans.end());
	
	cout << ans.size() << endl;
	for(auto it : ans) pf("%d %d\n", it.first, it.second);
	
	return 0;
}
