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
#define open freopen("filter.in","r",stdin); freopen("filter.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char s[1005][500];
bool bit[1005][1010];
int a[105];
int uk[1005];
vector<int> must[1005];

void pasang(int i, int j, int v) {
	while(v) {
		bit[i][j++] = (v & 1);
		v >>= 1;
	}
}

int trans(char c) {
	if('0' <= c && c <= '9') {
		return c - '0';
	}
	return c - 'a' + 10;
}

int main(void)
{
	open;
	int m, f, n, q, i, j, k;
	sf("%d %d", &m, &f);
	FORS(i, f) {
		sf("%d", &a[i]);
		a[i] %= m;
	}
	sf("%d", &n);
	FORS(i, n) sf("%s", s[i]);
	sf("%d", &q);
	FORS(i, q) {
		sf("%d", &uk[i]);
		uk[i] %= m;
	}
	FORS(i, q) {
		FORS(j, f) {
			must[i].push_back((uk[i] * a[j]) % m);
		}
		sort(must[i].begin(), must[i].end());
		must[i].resize(distance(must[i].begin(),
		unique(must[i].begin(), must[i].end())));
	}
	
	vector<int> ans;
	FORS(i, n) {
		int len = strlen(s[i]);
		FORS(j, len) {
			pasang(i, j * 4, trans(s[i][j]));
		}
		FORS(j, q) {
			bool valid = 1;
			int sz = (int) must[j].size();
			FORS(k, sz) {
				valid = bit[i][must[j][k]];
				if(valid == 0) {
					break;
				}
			}
			if(valid) {
				ans.push_back(i);
				break;
			}
		}
	}
	pf("%d ", ans.size());
	FORS(i, ans.size()) pf("%d ", ans[i]); nl;
	
	close;
	return 0;
}
