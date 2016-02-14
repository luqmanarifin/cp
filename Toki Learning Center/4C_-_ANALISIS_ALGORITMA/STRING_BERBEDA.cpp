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

char a[55], b[55];

int main(void)
{
	sf("%s %s", a, b);
	int lena = strlen(a);
	int lenb = strlen(b), i, j;
	int ans = inf;
	FOR(i, 0, lenb - lena) {
		int dif = 0;
		FORS(j, lena) {
			if(a[j] != b[i + j])
				dif++;
		}
		ans = min(ans, dif);
	}
	cout << ans << endl;
	return 0;
}
