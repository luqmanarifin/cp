#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define mt make_tuple
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int isi;
queue<pair<int,int> > q;
stack<pair<int,int> > s;
char tc[5];

int main(void)
{
	int n, a, b;
	sf("%d", &n);
	while(n--) {
		sf("%s", tc);
		if(tc[0] == 'a') {
			sf("%d %d", &a, &b);
			q.push(mp(a, b));
			isi += b;
			pf("%d\n", isi);
		} else if(tc[0] == 'd') {
			sf("%d", &a);
			isi -= a;
			pf("%d\n", q.front().first);
			while(a) {
				int del = min(a, q.front().second);
				a -= del;
				q.front().second -= del;
				if(q.front().second == 0) {
					q.pop();
				}
			}
		} else {
			while(!q.empty()) {
				s.push(q.front());
				q.pop();
			}
			while(!s.empty()) {
				q.push(s.top());
				s.pop();
			}
		}
	}
	
	return 0;
}
