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

int cnt[26];

int main(void)
{
	char s[N];
	sf("%s", s);
	int i, j, n = strlen(s);
	FORS(i, n) cnt[s[i]-'a']++;
	int odd = 0;
	FORS(i, 26) if(cnt[i] & 1) odd++;
	if(n % 2 && odd == 1) puts("YES");
	else if(n % 2 == 0 && odd == 0) puts("YES");
	else puts("NO");
	
	return 0;
}
