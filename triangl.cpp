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
	int a, b, c, d;
	sf("%d %d", &a, &b);
	int oon = abs(a) + abs(b);
	pair<int,int> asu = mp(a < 0? -oon : oon, 0);
	pair<int,int> dog = mp(0, b < 0? -oon : oon);
	if(asu.first > dog.first) swap(asu, dog);
	pf("%d %d %d %d\n", asu.first, asu.second, dog.first, dog.second);
	return 0;
}
