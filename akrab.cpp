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

char s[35][35];

bool vokal(int c) {
	return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
}

bool konso(int c) {
	return !vokal(c);
}

bool valid(int i, int j) {
	int a = (vokal(s[i][j]) && konso(s[i][j+1]));
	int b = (konso(s[i][j]) && vokal(s[i][j+1]));
	return (a || b);
}

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int n, i, j, ci, cj;
		reset(s, ' ');
		sf("%d", &n);
		FORS(i, n) sf("%s", s[i]);
		int ans = 0;
		FOR(i, 0, n-2) FOR(j, i+1, n-1) {
			int leni = strlen(s[i]);
			int lenj = strlen(s[j]);
			FOR(ci, 0, leni-2) {
				if(!valid(i, ci)) continue;
				FOR(cj, 0, lenj-2)
					if(s[i][ci] == s[j][cj] && s[i][ci+1] == s[j][cj+1]) {
						ans++;
						goto next;
					}
			}
			next:;
		}
		pf("%d\n", ans);
	}
	return 0;
}
