#include <bits/stdc++.h>

#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORS(i,n) for(i = 0; i < n; ++i)

using namespace std;

const int N = 1e5 + 5;

vector<int> near[N], ans;
int poin[N], a[N];
bool done[N];

void pencet(int pos) {
	int i;
	ans.push_back(pos);
	poin[pos]++;
	done[pos] = 1;
	FORS(i, near[pos].size()) {
		int edge = near[pos][i];
		poin[edge]++;
		if(!done[edge] && poin[edge] == a[edge])
			pencet(edge);
	}
}

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	while(m--) {
		int u, v;
		sf("%d %d", &u, &v);
		near[u].push_back(v);
		near[v].push_back(u);
	}
	FOR(i, 1, n) sf("%d", a + i);
	FOR(i, 1, n)
		if(!done[i] && poin[i] == a[i])
			pencet(i);
			
	cout << (int) ans.size() << endl;
	if(ans.size()) FORS(i, ans.size()) pf("%d ", ans[i]); nl;
	return 0;
}
