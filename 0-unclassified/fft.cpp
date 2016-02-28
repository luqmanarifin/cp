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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

vector<int> bit;
int n, d, a[N], b[N], pos[N];
LL x;

LL getnextX() {
	x = (x * 37 + 10007) % 1000000007;
	return x;
}

void init() {
	int i;
	FORS(i, n) a[i] = i + 1;
	FORS(i, n) swap(a[i], a[getnextX() % (i + 1)]);
	FORS(i, n) b[i] = (i < d);
	FORS(i, n) swap(b[i], b[getnextX() % (i + 1)]);
}

int main(void)
{
	int i, j;
	sf("%d %d %I64d", &n, &d, &x);
	init();
	FORS(i, n) pos[a[i]] = i;
	FORS(i, n) {
		int ans = 0;
		if(b[i]) bit.push_back(i);
		if(bit.size() > 330) {
			FORD(j, n, 1) {
				int p = pos[j];
				if(p <= i && b[i - p]) {
					ans = j;
					break;
				}
			}
		} else {
			FORS(j, bit.size())
				ans = max(ans, a[i - bit[j]]);
		}
		pf("%d\n", ans);
	}
	return 0;
}
