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

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

struct fenwick {
public:
	fenwick(int _n) : n(_n){
		int a, b, c;
		num.resize(n + 1);
		FORS(a, n + 1) {
			num[a].resize(n + 1);
			FORS(b, n + 1) {
				num[a][b].resize(n + 1);
			}
		}
	};
	void add(int x, int y, int z, LL val) {
		for(int a = x; a <= n; a |= a + 1)
			for(int b = y; b <= n; b |= b + 1)
				for(int c = z; c <= n; c |= c + 1)
					num[a][b][c] += val;
	}
	LL cari(int a, int b, int c, int x, int y, int z) {
		return find(x, y, z) - find(a-1, y, z) - find(x, b-1, z) - find(x, y, c-1)
		+ find(a-1, b-1, z) + find(x, b-1, c-1) + find(a-1, y, c-1) - find(a-1, b-1, c-1);
	}
private:
	LL find(int x, int y, int z) {
		LL ret = 0;
		for(int a = x; a >= 0; a = (a & (a + 1))-1)
			for(int b = y; b >= 0; b = (b & (b + 1))-1)
				for(int c = z; c >= 0; c = (c & (c + 1))-1)
					ret += num[a][b][c];
		return ret;
	}	
	int n;
	vector<vector<vector<LL> > > num;
};

int main(void)
{
	//puts("gukguk");
	int n, q;
	sf("%d %d", &n, &q);
	fenwick fen(n);
	while(q--) {
		char s[15];
		int x1, x2, y1, y2, z1, z2;
		LL val;
		sf("%s", s);
		if(s[0] == 'a') {
			sf("%d %d %d %lld", &x1, &y1, &z1, &val);
			fen.add(x1, y1, z1, val);
		} else {
			sf("%d %d %d %d %d %d", &x1, &y1, &z1, &x2, &y2, &z2);
			pf("%lld\n", fen.cari(min(x1, x2), min(y1, y2), min(z1, z2),
				max(x1, x2), max(y1, y2), max(z1, z2)));
		}
	}
	
	return 0;
}
