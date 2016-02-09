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
#define OUT { puts("impossible"); return 0; }

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bool fix[N], ada[N];
vector<int> adj[N];

bool bisa(int pos, int st) {
	int i;
	FORS(i, adj[pos].size()) {
		int near = adj[pos][i];
		if(fix[near] && fix[pos] && ada[pos] == ada[near]) {
			return 0;
		}
		if(fix[pos]) continue;
		if(fix[near] {
			if(st == ada[near]) {
				ada[pos] = st ^ 1;
			} else {
				ada[pos] = st;
			}
			fix[pos] = 1;
		} else {
			if(st == ada[near]) {
				if(!bisa(near, st ^ 1)) {
					return 0;
				}
			}
		}
	}
	ada[pos] = st;
	return 1;
}

int main(void)
{
	int n, m;
	sf("%d %d", &n, &m);
	FORS(i, m) {
		int a, b, c;
		sf("%d %d %d", &a, &b, &c);
		if(c == 0) {
			if(fix[a] && ada[a]) OUT;
			if(fix[b] && ada[b]) OUT;
			fix[a] = 1;
			fix[b] = 1;
			ada[a] = 0;
			ada[b] = 0;
		} else if(c == 2) {
			if(fix[a] && ada[a] == 0) OUT;
			if(fix[b] && ada[b] == 0) OUT;
			fix[a] = 1;
			fix[b] = 1;
			ada[a] = 1;
			ada[b] = 1;
		} else {
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
	}
	FOR(i, 1, n) {
		FORS()
	}
	
	return 0;
}
