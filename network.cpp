#include <bits/stdc++.h>

/**
 * Good Bye 2014
 * Problem : D
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

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

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n;
double pec[N];
int anak[N], l[N];
vector<pair<int,int > > data;
vector<int> edge[N];

double hitung(int a) {
	double ret = 1.0;
	int i;
	FORS(i, 3) ret *= (DB)(a - i)/(n - i);
	return ret;
}

int dfs(int now, int prev) {
	int i;
	int ret = 1;
	FORS(i, edge[now].size()) {
		int id = edge[now][i];
		int near = data[id].first;
		if(near == prev) continue;
		int sumchild = dfs(near, now);
		anak[id/2] = sumchild;
		ret += sumchild;
	}
	return ret;
}

int main(void)
{
	int i, j;
	sf("%d", &n);
	int id = 0;
	FORS(i, n-1) {
		int a, b;
		sf("%d %d %d", &a, &b, &l[i]);
		data.push_back(mp(b, l[i]));
		edge[a].push_back(id++);
		data.push_back(mp(a, l[i]));
		edge[b].push_back(id++);
	}
	assert(dfs(1, -1) == n);
	double ans = 0.0;
	FORS(i, n-1) {
		pec[i] = 1.0 - hitung(anak[i]) - hitung(n - anak[i]);
		ans += pec[i]*l[i];
	}
	int q;
	sf("%d", &q);
	while(q--) {
		int at, w;
		sf("%d %d", &at, &w);
		at--;
		ans -= pec[at]*l[at];
		l[at] = w;
		ans += pec[at]*l[at];
		pf("%.15lf\n", 2*ans);
	}
	
	return 0;
}
