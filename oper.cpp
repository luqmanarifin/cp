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
const int N = (1 << 19) + 10;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int tree[N], p;

int main(void)
{
	int n, m, i, j;
	sf("%d %d", &n, &m);
	p = (1 << n);
	FORS(i, p) sf("%d", &tree[p + i]);
	int lv = n - 1, cur = p - (1 << lv);
	for(i = p - 1; i; i--) {
		if(i < cur) {
			lv--;
			cur -= (1 << lv);
		}
		int stat = (n - lv) & 1;
		if(stat) tree[i] = tree[2*i] | tree[2*i+1];
		else tree[i] = tree[2*i] ^ tree[2*i+1];
	}
	while(m--) {
		int k, b;
		sf("%d %d", &k, &b);
		i = p + k - 1;
		tree[i] = b; i /= 2;
		int stat = 1;
		while(i) {
			if(stat) tree[i] = tree[2*i] | tree[2*i+1];
			else tree[i] = tree[2*i] ^ tree[2*i+1];
			stat ^= 1;
			i /= 2;
		}
		pf("%d\n", tree[1]);
	}
	return 0;
}
