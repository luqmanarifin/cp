#include <bits/stdc++.h>

/**
 * Good Bye 2014
 * Problem : B
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int p[305];
char s[305][305];
vector<int> edge[305];
bool done[305];

vector<int> dfs(int now) {
	vector<int> ret;
	if(done[now]) return ret;
	ret.push_back(now);
	done[now] = 1;
	int i, j;
	FORS(i, edge[now].size()) {
		int near = edge[now][i];
		vector<int> hn = dfs(near);
		FORS(j, hn.size()) ret.push_back(hn[j]);
	}
	return ret;
}

int main(void)
{
	int i, j, n;
	sf("%d", &n);
	FORS(i, n) sf("%d", &p[i]);
	FORS(i, n) sf("%s", s[i]);
	FORS(i, n) FORS(j, n) {
		if(s[i][j] == '1') edge[i].push_back(j);
	}
	FORS(i, n) {
		vector<int> ret = dfs(i);
		if(ret.empty()) continue;
		vector<int> num;
		FORS(i, ret.size()) num.push_back(p[ret[i]]);
		sort(num.begin(), num.end());
		sort(ret.begin(), ret.end());
		FORS(i, ret.size()) p[ret[i]] = num[i];
	}
	FORS(i, n) pf("%d ", p[i]); nl;
	
	return 0;
}
