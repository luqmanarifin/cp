#include <bits/stdc++.h>
#include <iomanip>

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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair
#define MATIO { puts("NO"); return 0; }

const LL mod = 1e9+7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int low = 0, mid = 0;

int main(void)
{
	int n; sf("%d", &n);
	while(n--) {
		int duid;
		sf("%d", &duid);
		if(duid == 25) low++;
		else if(duid == 50) {
			mid++;
			if(!low) MATIO
			low--;
		} else {
			if(low && mid) low--, mid--;
			else if(low >= 3) low -= 3;
			else MATIO
		}	
	}
	
	puts("YES");
	
	return 0;
}