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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL INF = 4e18;
const int inf = 2e9;
const int m = 64;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> edge[8];
LL a[m], t[m][m], temp[m][m], mod;

void temptemp() {
	int i, j, k;
	LL res[m][m];
	reset(res, 0);
	FORS(i, m) FORS(j, m) FORS(k, m) {
		res[i][j] = (res[i][j] + temp[i][k]*temp[k][j]) % mod;
	}
	FORS(i, m) FORS(j, m)
		temp[i][j] = res[i][j];
}

void ttemp() {
	int i, j, k;
	LL res[m][m];
	reset(res, 0);
	FORS(i, m) FORS(j, m) FORS(k, m) {
		res[i][j] = (res[i][j] + t[i][k]*temp[k][j]) % mod;
	}
	FORS(i, m) FORS(j, m)
		temp[i][j] = res[i][j];
}

void atemp() {
	int i, j, k;
	LL res[m];
	reset(res, 0);
	FORS(j, m) FORS(k, m) {
		res[j] = (res[j] + a[k]*temp[k][j]) % mod;
	}
	FORS(j, m)
		a[j] = res[j];
}

void power(int k) {
	if(k == 0) return;
	power(k >> 1);
	temptemp();
	if(k & 1) ttemp();
}

int main(void)
{
	int tt, i, j, k;
	FORS(i, 4) {
		edge[i].push_back(i+4);
		edge[i+4].push_back(i);
		edge[i].push_back((i+1) % 4);
		edge[(i+1) % 4].push_back(i);
		edge[i+4].push_back((i+5 == 8? 4 : i+5));
		edge[(i+5 == 8? 4 : i+5)].push_back(i+4);
	}
	FORS(i, 64) {
		int to = i / 8;
		int from = i % 8;
		bool ada = 0;
		FORS(j, edge[to].size())
			if(edge[to][j] == from)
				ada = 1;
		if(!ada) continue;
		FORS(j, edge[from].size()) {
			int near = edge[from][j];
			if(near == to) continue;
			t[from*8 + near][i] = 1;
		}
	}
	sf("%d", &tt);
	while(tt--) {
		reset(a, 0);
		FORS(i, m) FORS(j, m) temp[i][j] = (i == j);
		char st, fn;
		int start, finish, k;
		sf("\n%c %c %d %lld", &st, &fn, &k, &mod);
		start = st - 'A';
		finish = fn - 'A';
		//pf("%d %d\n", start, finish);
		FORS(i, edge[start].size()) {
			int near = edge[start][i];
			a[near*8 + start] = 1;
		}
		power(k - 1);
		atemp();
		LL ans = 0;
		FORS(i, 8) {
			ans += a[finish*8 + i];
		}
		pf("%lld\n", ans % mod);
	}
	
	return 0;
}
