#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef vector< ii > vii;

const int mod = 1e9+7;

int n, m;

vector< vii > al;
vector<int> vis;

bool dfs(int v, int c) {
	vis[v] = c;
	bool ret = true;
	for(int i = 0; i<al[v].size(); i++) {
		ii u = al[v][i];
		if(vis[u.first] == -1) {
			if(!dfs(u.first, (u.second ? c : 1-c)))
				ret = false;
		}
		else {
			if((u.second && c != vis[u.first]) || (!u.second && c == vis[u.first]))
				ret = false;
		}
	}
	return ret;
}

int main() {
	scanf("%d%d", &n, &m);
	al.assign(n+1, vii());
	vis.assign(n+1, -1);
	while(m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		al[a].push_back(ii(b, c));
		al[b].push_back(ii(a, c));
	}
	long long res = (mod+1)/2;
	for(int i = 1; i<=n; i++)
		if(vis[i] == -1) {
			if(dfs(i, 1)){
				res <<= 1;
				res %= mod;
			}
			else {
				res = 0;
				break;
			}
		}
	printf("%I64d\n", res);
	return 0;
}