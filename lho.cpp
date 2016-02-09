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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int t;
	sf("%d", &t);
	while(t--) {
		int i, j;
		char s[105];
		sf("%s", s);
		int ans = 0;
		int n = strlen(s);
		i = 0;
		while(i < n) {
			if(s[i] == 'l') {
				if(i + 1 < n && s[i + 1] == 'h') {
					j = i + 2;
					while(j < n && s[j] == 'o') j++;
					if(j < n && s[j] == '?') {
						ans = max(ans, j - i - 2);
					}
				}
			}
			i++;
		}
		pf("%d\n", ans);
	}
	return 0;
}
