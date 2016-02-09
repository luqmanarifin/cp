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
const int N = 1e5 + 5;

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) {
	if(!a || !b) return max(a,b);
	return a/gcd(a, b)*b;
}

int kelas[N], maxClass = 1;
vector<int> inKelas[N], anak[N], edge[N];
LL son[N], a[N];

void buildTree(int now, int prev) {
	int i;
	son[prev]++;
	anak[prev].push_back(now);
	kelas[now] = kelas[prev] + 1;
	maxClass = max(maxClass, kelas[now]);
	inKelas[kelas[now]].push_back(now);
	if(edge[now].size())
	FORS(i, edge[now].size()) {
		int adj = edge[now][i];
		if(adj == prev) continue;
		buildTree(adj, now);
	}
}

int main(void)
{
	int i, n, j, k;
	sf("%d", &n);
	reset(son, 0);
	FOR(i,1,n) {
		sf("%I64d", &a[i]);
	}
	
	FORS(i, n-1) {
		int x, y;
		sf("%d %d", &x, &y);
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	kelas[1] = 1;
	inKelas[1].push_back(1);
	FORS(i, edge[1].size())
		buildTree(edge[1][i], 1);
		
	FOR(i,2,n) if(!son[i]) son[i] = 1;
	
	LL ans = 0;
	FORD(i, maxClass - 1, 1) {
		vector<int> now = inKelas[i];
		FORS(j, now.size()) {
			int dad = now[j];
			if(anak[dad].size()) {
				LL mini = INF, sum = 0;
				LL kpk = 1;
				FORS(k, anak[dad].size()) {
					int node = anak[dad][k];
					kpk = lcm(kpk, son[node]);
					sum += a[node];
					if(a[node] < mini)
						mini = a[node];
				}
				a[dad] = (mini/kpk)*kpk*son[dad];
				ans += sum - a[dad];
				son[dad] *= kpk;
			}
		}
	}
	pf("%I64d\n", ans);
	/*
	FOR(i,1,n) pf("%I64d ", son[i]); nl;
	FOR(i,1,n) pf("%I64d ", a[i]); nl;
	FOR(i,1,n) pf("%d ", kelas[i]); nl;
	*/
	return 0;
}
