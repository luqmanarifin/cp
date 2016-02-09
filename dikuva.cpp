#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 1e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

vector<pair<int,int> > edge[105];
int path[105], prev[105];

void backtrack(int now) {
	if(now == 1) return;
	int i, back = prev[now];
	FORS(i, edge[now].size()) {
		if(edge[now][i].first == back) {
			edge[now][i].second *= -1;
			break;
		}
	}
	FORS(i, edge[back].size()) {
		if(edge[back][i].first == now) {
			edge[back][i].second = inf;
			break;
		}
	}
	backtrack(prev[now]);
} 

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int n, i, j, k, m;
	while(1) {
		priority_queue<pair<int,int> > pq;
		FORS(i, 105) path[i] = inf;
		FORS(i, 105) edge[i].clear();
		reset(prev, 0);
		sf("%d", &n);
		if(n == 0) break;
		sf("%d", &m);
		while(m--) {
			int a, b, c;
			sf("%d %d %d", &a, &b, &c);
			edge[a].push_back(mp(b, c));
			edge[b].push_back(mp(a, c));
		}
		
		path[1] = 0;
		pq.push(mp(0, 1));
		while(!pq.empty()) {
			int now = pq.top().second;
			int cost = -pq.top().first;
			//pf("now %d %d\n", now, cost);
			pq.pop();
			if(cost != path[now]) continue;
			FORS(i, edge[now].size()) {
				int near = edge[now][i].first;
				int ncos = edge[now][i].second;
				if(cost + ncos < path[near]) {
					prev[near] = now;
					path[near] = cost + ncos;
					pq.push(mp(-path[near], near));
				}
			}
		}
		int ans = 0;
		if(path[n] == inf) {
			puts("Back to jail");
			continue;
		}
		ans = path[n];
		backtrack(n);
		
		FORS(i, 105) path[i] = inf;
		path[1] = 0;
		pq.push(mp(0, 1));
		while(!pq.empty()) {
			int now = pq.top().second;
			int cost = -pq.top().first;
			//pf("now %d %d\n", now, cost);
			pq.pop();
			if(cost != path[now]) continue;
			FORS(i, edge[now].size()) {
				int near = edge[now][i].first;
				int ncos = edge[now][i].second;
				if(cost + ncos < path[near]) {
					path[near] = cost + ncos;
					pq.push(mp(-path[near], near));
				}
			}
		}
		if(path[n] == inf) {
			puts("Back to jail");
			continue;
		}
		ans += path[n];
		pf("%d\n", ans);
	}
	
	//close;
	return 0;
}