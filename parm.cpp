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
const int N = 1e6 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

map<int,int> cnt, op;
int a[N], fj[N];
long long bit[N];

void add(int pos, int val) {
	for(; pos <= N; pos |= pos + 1)
		bit[pos] += val;
}

long long find(int pos) {
	long long ret = 0;
	for(; pos >= 0; pos = (pos & (pos + 1)) - 1)
		ret += bit[pos];
	return ret;
}

int main(void)
{
	int n, i, j;
	sf("%d", &n);
	FORS(i, n) sf("%d", a + i);
	FORS(i, n) {
		cnt[a[i]]++;
		add(n - cnt[a[i]], 1);
	}
	LL ans = 0;
	FORM(i, n) {
		op[a[i]]++;
		add(n - cnt[a[i]], -1);
		cnt[a[i]]--;
		ans += find(n - op[a[i]] - 1);
	}
	cout << ans << endl;
	return 0;
}
