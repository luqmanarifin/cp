#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

map<int, bool> ada;

int main(void)
{
	ios_base::sync_with_stdio(false);
	int n, i, a[100005];
	sf("%d", &n);
	FORS(i,n) 
		sf("%d", &a[i]);
	
	sort(a, a + n);
	FORS(i, n-1)
		if(a[i] != a[i+1])
			if(a[i]*2 > a[i+1]) {
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}
