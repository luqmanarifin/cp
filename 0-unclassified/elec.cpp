#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = b; i >= a; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n-i; i >= 0; --i)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1e5 + 5;

bool white[N];
int d[N];
vector<int> ans, node[N];

void dfs(int now, int prev) {
	d[now] = white[now];
	int i;
	FORS(i,node[now].size()) {
		int to = node[now][i];
		if(to == prev)
			continue;
		dfs(to, now);
		d[now] += d[to];
	}
}

int main(void)
{
	int n, i, x, y, kod;
	sf("%d", &n);
	FORS(i,n-1) {
		sf("%d %d %d", &x, &y, &kod);
		node[x].push_back(y);
		node[y].push_back(x);
		if(kod == 2) {
			white[x] = true;
			white[y] = true;
		}
	}
	dfs(1,0);
	
	FOR(i,1,n)
		if(white[i] && d[i] == 1)
			ans.push_back(i);
			
	random_shuffle(ans.begin(), ans.end());
	
	pf("%d\n", ans.size());
	FORS(i,ans.size())
		pf("%d ", ans[i]);
	nl;
		
	return 0;
}