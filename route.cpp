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
const int N = 1e5 + 5;
const LL inf = 4e18;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int dis[N], ada[N];
vector<int> near[N];
LL sum[N], total;

LL dfs(int now, int prev) {
	LL temp = dis[now]; int i;
	FORS(i, near[now].size()) {
		int adj = near[now][i];
		if(prev == adj) continue;
		if(abs(sum[now] - sum[adj]) + dis[adj] < temp)
			temp = abs(sum[now] - sum[adj]) + dfs(adj, now);
	}
	return temp;
}

int main(void)
{
	int n, i;
	sf("%d", &n);
	FOR(i,0,n) sf("%d", &dis[i]);
	
	ada[0] = 1;
	FORS(i,n) {
		int a, b, c;
		sf("%d %d %d", &a, &b, &c);
		if(ada[a]) {
			sum[b] = sum[a] + c;
		} else { // ada[b]
			sum[a] = sum[b] + c;
		}
		ada[a]++;
		ada[b]++;
		near[a].push_back(b);
		near[b].push_back(a);
		total += 2LL*c;
	}
	
	LL ans = inf;
	FOR(i,1,n)
		if(ada[i] == 1) {
			LL cur = total - sum[i] + dfs(i, -1);
			ans = min(ans, cur);
		}
	
	cout << ans << endl;
	return 0;
}
