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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int to[200];
bool adj[200][200];

void add(int a, int b) {
	adj[a][b] = adj[b][a] = 1;
}

int main(void)
{
	int i, j, k;
	sf("%d", &k);
	add(2, 3); add(2, 4);
	to[0] = 3;
	int now = 5;
	FOR(i, 1, 31) {
		to[i] = now;
		add(now, now-1);
		add(now, now-2);
		add(now+1, now-1);
		add(now+1, now-2);
		now += 2;
	}
	add(now, now-1);
	add(now, now-2);
	add(now+1, now-1);
	add(now+1, now-2);
	now += 2;
	
	add(now++, 1);
	int mask;
	FORD(mask, 31, 0) {
		add(now, now-1);
		if(k & (1 << mask)) add(now, to[mask]);
		now++;
	}
	cout << now << endl;
	FOR(i, 1, now) {
		FOR(j, 1, now) {
			if(i == j) pf("N");
			else pf(adj[i][j]? "Y" : "N");
		}
		nl;
	}
	return 0;
}
