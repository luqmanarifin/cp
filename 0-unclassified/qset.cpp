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
const double eps = 1e-13;
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n;
int bit[3][N];
char s[N];
LL pre[N];

void add_pre(int i, LL val) {
	for(; i <= n; i |= i + 1) {
		pre[i] += val;
	}
}

LL get_pre(int i) {
	LL temp = 0;
	for(; i >= 0; i = (i & (i + 1)) - 1) {
		temp += pre[i];
	}
	return temp;
}

void add(int i, int j, int v) {
	for(; j <= n; j |= j + 1) {
		bit[i][j] += v;
	}
}

int get(int i, int j) {
	int ret = 0;
	for(; j >= 0; j = (j & (j + 1)) - 1) {
		ret += bit[i][j];
	}
	return ret;
}

LL compute(LL a) {
	return a * (a - 1) / 2;
} 

int main(void)
{
	//open;
	int i, j, m;
	sf("%d %d", &n, &m);
	sf("%s", &s[1]);
	int tot = 0;
	FOR(i, 1, n) {
		s[i] -= '0';
		tot += s[i];
		tot %= 3;
		add_pre(i, s[i]);
		add(tot, i, 1);
	}
	while(m--) {
		int t, a, b;
		sf("%d %d %d", &t, &a, &b);
		if(t == 1) {
			add(get_pre(a) % 3, a, -1);
			add_pre(a, -s[a]);
			s[a] = b;
			add_pre(a, s[a]);
			add(get_pre(a) % 3, a, 1);
		} else {
			LL ret[] = {1, 0, 0};
			LL ans = 0;
			FORS(i, 3) ret[i] += get(i, b) - get(i, a - 1);
			FORS(i, 3) ans += compute(ret[i]);
			pf("%lld\n", ans);
		}
	}
	
	//close;
	return 0;
}
