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
const double eps = 1e-13;
const int N = 2e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

LL sto[N], m;
pair<pair<int, LL>, int> ser[N];
bool ans[N];

#define x first
#define y second

int main(void)
{
	int n, i, j;
	sf("%d %I64d", &n, &m);
	FORS(i, n) {
		sf("%I64d %d", &ser[i].x.y, &ser[i].x.x);
		ser[i].y = i + 1;
		sto[i] = ser[i].x.y;
	}
	sort(sto, sto + n);
	sort(ser, ser + n);
	reverse(sto, sto + n);
	reverse(ser, ser + n);
	FORS(i, n) {
		if(i) sto[i] += sto[i-1];
		if(sto[i] >= m) break;
	}
	int need = i + 1;
	LL peta = 0;
	FORS(i, need) {
		peta += ser[i].x.y;
	}
	FORS(i, n) {
		if(ser[i].x.x == 0)
			break;
	}
	int last1 = min(need-1, i-1);
	int to0 = max(need, i);
	while(peta < m) {
		peta = peta - ser[last1].x.y + ser[to0].x.y;
		last1--;
		to0++;
	}
	int w = 0;
	FORS(i, n) {
		if(ser[i].x.x && i <= last1) ans[ser[i].y] = 1, w++;
		if(ser[i].x.x == 0 && i < to0) ans[ser[i].y] = 1;
	}
	pf("%d %d\n", need, w);
	FOR(i, 1, n) if(ans[i]) pf("%d ", i); nl;
	
	return 0;
}
