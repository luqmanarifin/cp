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

#define open freopen("fraud.in","r",stdin); freopen("fraud.out","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

char tc[1005][10];
char res[1005][10];

int main(void)
{
	open;
	char s[100];
	sf("%s", s);
	int n, i, j, ans = 0;
	sf("%d", &n);
	FORS(i, n) {
		sf("%s", tc[i]);
		bool valid = 1;
		FORS(j, 9) {
			if(s[j] == '*') continue;
			if(s[j] != tc[i][j]) {
				valid = 0;
				break;
			}
		}
		if(valid) {
			FORS(j, 9) res[ans][j] = tc[i][j];
			ans++;
		}
	}
	cout << ans << endl;
	FORS(i, ans) { FORS(j, 9) pf("%c", res[i][j]); nl; }
	close;
	return 0;
}
