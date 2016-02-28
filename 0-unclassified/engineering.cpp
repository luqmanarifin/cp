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

char s[100];
int n, i, sub, ans = 0;

int main()
{
	sf("%s", &s);
	sub = 0; n = strlen(s);
	FOR(i,1,n-1){
		if(s[i] != s[i-1] && (i-sub)%2 == 0) ans++;
		if(s[i] != s[i-1]) sub = i;
	}
	if((n-sub) % 2 == 0 && s[n-1] == s[n-2]) ans++;
	cout << ans << endl;
	return 0;
}