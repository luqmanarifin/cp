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
const int N = 5e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> pos;
bitset<N> ada;
int ans, day;

int main(void)
{
	int d, i, j, n, x;
	sf("%d %d", &n, &d);
	pos.push_back(0);
	FORS(i, n) {
		sf("%d", &x);
		int len = (int) pos.size();
		FORS(j, len)
			if(!ada[pos[j]+x]) {
				pos.push_back(pos[j] + x);
				ada[pos[j]+x] = 1;
			}
	}
	sort(pos.begin(), pos.end());
	i = 0;
	while(i < pos.size()) {
		while(i < pos.size() && ans + d >= pos[i]) i++;
		if(ans != pos[i-1]) {	// ada barang yang berhasil diambil, day nambah
			ans = pos[i-1];
			day++;
		} else break;		// gak ada barang, minggat
	}
	pf("%d %d\n", ans, day);
	return 0;
}
