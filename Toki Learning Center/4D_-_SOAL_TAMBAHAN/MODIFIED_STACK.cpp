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

vector<pair<int,int> > s;
int isi;
char tc[5];

int main(void)
{
	int n, a, b, i, j;
	sf("%d", &n);
	while(n--) {
		sf("%s", tc);
		if(tc[0] == 'a') {
			if(tc[2] == 'd') {	// add
				sf("%d %d", &a, &b);
				s.push_back(mp(a, b));
				isi += b;
				pf("%d\n", isi);
			} else {					// adx
				sf("%d", &a);
				FORS(i, s.size()) {
					s[i].first += a;
				}
			}
		} else {
			if(tc[2] == 'l') {	// del
				sf("%d", &a);
				isi -= a;
				pf("%d\n", s.back().first);
				while(a) {
					int del = min(a, s.back().second);
					a -= del;
					s.back().second -= del;
					if(s.back().second == 0) {
						s.pop_back();
					}
				}
			} else {					// dex
				sf("%d", &a);
				FORS(i, s.size()) {
					s[i].first -= a;
				}
			}
		}
	}	
	
	return 0;
}
