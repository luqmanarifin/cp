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
const int N = 1e5 + 5;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

map<int, int> cnt;
int a[N];

int main(void)
{
	int i, j, n, q;
	sf("%d", &n);
	FOR(i, 1, n) {
		sf("%d", a + i);
		cnt[a[i]]++;
	}
	if(cnt[a[1]] == n) {
		puts("0");
		return 0;
	}
	sf("%d", &q);
	FOR(i, 1, q) {
		int b, c;
		sf("%d %d", &b, &c);
		cnt[a[b]]--;
		a[b] = c;
		int num = ++cnt[c];
		if(num == n) {
			pf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
	return 0;
}
