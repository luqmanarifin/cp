#include <bits/stdc++.h>

/**
 * TOKI Open Contest Agustus 2014
 * Problem : 
 * Luqman Arifin (kadalbonek)
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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int main(void)
{
	int i = 1, j, a, b, now = 3, ans = 0;
	sf("%d %d", &a, &b);
	if(a == 0 && b == 0) {
		puts("0");
		return 0;
	}
	while(i != a) {
		ans += now;
		now += 2;
		i++;
	}
	ans += b + 1;
	cout << ans << endl;
	return 0;
}
