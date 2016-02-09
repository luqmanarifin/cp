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

char s[N];

int main(void)
{
	//open;
	int n, m, i, j;
	sf("%d %d", &n, &m);
	sf("%s", &s[1]);
	FOR(i, 1, n) s[i] -= '0';
	while(m--) {
		int t, a, b;
		sf("%d %d %d", &t, &a, &b);
		if(t == 1) {
			s[a] = b;
		} else {
			LL ans = 0;
			FOR(i, a, b) {
				int sum = 0;
				FOR(j, i, b) {
					sum += s[j];
					if(sum % 3 == 0) {
						ans++;
					}
				}
			}
			pf("%lld\n", ans);
		}
	}
	
	//close;
	return 0;
}
