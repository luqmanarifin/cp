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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int a[N];
map<int,int> cur;

int main(void)
{
	int n, i; LL k;
	sf("%d %I64d", &n, &k);
	FORS(i, n) {
		sf("%d", a + i);
		cur[a[i]]++;
	}
	sort(a, a + n);
	int w = cur[a[0]];
	if(k <= 1LL*w*n) {
		pf("%d %d\n", a[0], a[(k-1)/w]);
		return 0;
	}
	k -= 1LL*w*n;
	i = 1;
	while(i < n) {
		if(a[i-1] != a[i]) {
			w = cur[a[i]];
			if(k <= 1LL*w*n) {
				pf("%d %d\n", a[i], a[(k-1)/w]);
				return 0;
			}
			k -= 1LL*w*n;
		}
		i++;
	}
	
	return 0;
}
