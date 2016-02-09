#include <bits/stdc++.h>

/**
 * Good Bye 2014
 * Problem : F
 * Luqman Arifin (kadalbonek)
 * بسم الله الرحمان الرحيم
 */

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
const int N = 4005;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int temp[N];
int lef[N][N];
int rig[N][N];
int c[N], h[N], t[N];
pair<int,pair<int,int> > e[N];

int main(void)
{
	//open;
	int i, j, n, p;
	sf("%d %d", &n, &p);
	FORS(i, n) {
		sf("%d %d %d", &c[i], &h[i], &t[i]);
		e[i] = mp(t[i], mp(c[i], h[i]));
	}
	sort(e, e + n);
	FORS(i, n) {
		t[i] = e[i].first;
		c[i] = e[i].second.first;
		h[i] = e[i].second.second;
	}
	int beg = 0;
	while(beg < n) {
		int end = beg;
		while(end + 1 < n && t[end + 1] / p == t[beg] / p) {
			end++;
		}
		reset(temp, 0);
		FOR(i, beg, end) {
			FORD(j, N - 1, c[i]) {
				temp[j] = max(temp[j], temp[j - c[i]] + h[i]);
			}
			FORS(j, N) {
				lef[i][j] = temp[j];
			}
		}
		
		reset(temp, 0);
		FORD(i, end, beg) {
			FORD(j, N - 1, c[i]) {
				temp[j] = max(temp[j], temp[j - c[i]] + h[i]);
			}
			FORS(j, N) {
				rig[i][j] = temp[j];
			}
		}
		
		beg = end + 1;
	}
	int q;
	sf("%d", &q);
	while(q--) {
		int time, duit;
		sf("%d %d", &time, &duit);
		int first = -1, last = -1;
		FORS(i, n) {
			if(t[i] <= time && time < t[i] + p) {
				if(first == -1) {
					first = i;
				}
				last = i;
			}
		}
		if(first == -1) {
			puts("0");
			continue;
		}
		if(t[first] / p == time / p) {
			pf("%d\n", lef[last][duit]);
			continue;
		}
		if(t[last] / p == time / p - 1) {
			pf("%d\n", rig[first][duit]);
			continue;
		}
		int ans = 0;
		FOR(i, 0, duit) {
			ans = max(ans, lef[last][i] + rig[first][duit - i]);
		}
		pf("%d\n", ans);
	}
	
	//close;
	return 0;
}
