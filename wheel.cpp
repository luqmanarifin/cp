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

LL gcd(LL a, LL b) { return b? gcd(b, a%b): a; }
LL lcm(LL a, LL b) { return a/ gcd(a, b)*b; }

LL a[1005], b[1005];
bool rot[1005], done[1005];
LL x[1005], y[1005], r[1005];

bool intersect(int i, int j) {
	return (x[i] - x[j])*(x[i] - x[j]) +
	(y[i] - y[j])*(y[i] - y[j]) == (r[i] + r[j])*(r[i] + r[j]);
}

void simple(LL &c, LL &d) {
	LL fpb = gcd(c, d);
	c /= fpb;
	d /= fpb;
}

int main(void)
{
	int t, i, j, n;
	sf("%d", &t);
	while(t--) {
		reset(a, 0);
		reset(b, 0);
		reset(rot, 0);
		reset(done, 0);
		sf("%d", &n);
		FORS(i, n) {
			sf("%I64d %I64d %I64d", &x[i], &y[i], &r[i]);
		}
		a[0] = 1; b[0] = 1;
		done[0] = 1;
		stack<int> st;
		st.push(0);
		while(!st.empty()) {
			int now = st.top();
			st.pop();
			FORS(i, n) {
				if(intersect(now, i) && !done[i]) {
					LL r1 = r[now];
					LL r2 = r[i];
					LL a1 = a[now];
					LL b1 = b[now];
					LL fpb;
					simple(r1, r2);
					simple(r1, b1);
					simple(a1, r2);
					simple(a1, b1);
					a[i] = r1 * a1;
					b[i] = r2 * b1;
					simple(a[i], b[i]);
					rot[i] = (rot[now] ^ 1);
					done[i] = 1;
					st.push(i);
				}
			}
		}
		FORS(i, n) {
			if(done[i]) {
				pf("%I64d", a[i]);
				if(b[i] != 1) pf("/%I64d ", b[i]);
				else pf(" ");
				pf(rot[i]? "counterclockwise" : "clockwise");
				nl;
			} else puts("not moving");
		}
	}
	
	return 0;
}
