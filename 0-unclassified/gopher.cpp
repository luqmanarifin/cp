#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
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
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

#define x first
#define y second
#define pdd pair<double, double>

double lim;
vector<int> vis[105];
pdd gop[105], hol[105];
bool done[105];

bool cmp(int l, int r) {
	return (int) vis[l].size() < (int) vis[r].size();
}

double dist(pdd a, pdd b) {
	double dx = a.x - b.x;
	double dy = b.x - b.y;
	return dx*dx + dy*dy;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	//open;
	int n, m, i, j;
	double s, v;
	while(cin >> n >> m >> s >> v) {
		lim = s*v;
		lim *= lim;
		FORS(i, 105) vis[i].clear();
		reset(done, 0);
		FORS(i, n) cin >> gop[i].x >> gop[i].y;
		FORS(i, m) cin >> hol[i].x >> hol[i].y;
		int prio[105];
		FORS(i, n) {
			FORS(j, m) {
				if(dist(gop[i], hol[j]) < lim)
					vis[i].push_back(j);
			}
			prio[i] = i;
		}
		sort(prio, prio + n, cmp);
		int got = 0;
		FORS(i, n) {
			int id = prio[i];
			FORS(j, vis[id].size()) {
				int jd = vis[id][j];
				if(!done[jd]) {
					got++;
					done[jd] = 1;
					break;
				}
			}
		}
		pf("%d\n", n - got);
	}
	
	//close;
	return 0;
}