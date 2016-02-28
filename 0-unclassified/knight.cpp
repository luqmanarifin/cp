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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int good[2][2], asu[2][2], a, b, c, d;

int main(void)
{
	int t; sf("%d", &t);
	while(t--) {
		int i, j;
		reset(good, 0);
		reset(asu, 0);
		FORS(i, 8) {
			char s[10];
			sf("%s", s);
			FORS(j, 8) {
				if(s[j] == '.')
					good[i&1][j&1] = 1;
				if(s[j] == 'K') {
					asu[i&1][j&1]++;
					if(asu[i&1][j&1] - 1)
						c = i, d = j;
					else
						a = i, b = j;
				}
			}
		}
		bool iya = 0;
		FORS(i, 2) FORS(j, 2) if(asu[i][j] == 2) {
			int kiki = abs(a - c)/2;
			int ainun = abs(b - d)/2;
			int inas = max(kiki, ainun);
			if(inas % 2 == 0)
				if(((a/2) % 2 == (b/2) % 2) == ((c/2) % 2 == (d/2) % 2))
					iya = 1;
		}
		puts(iya? "YES" : "NO");
	}
	
	return 0;
}
