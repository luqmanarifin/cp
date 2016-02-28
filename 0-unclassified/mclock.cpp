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

const LL mod = 1e9 + 7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n; 

int main(void)
{
	sf("%d", &n);
	while(n--) {
		char x[5];
		sf("%s", x);
		int in = ((x[0]-'0')*10+(x[1]-'0'))*60 + (x[3]-'0')*10 + (x[4]-'0');
		int ans = 12*60 - in;
		if(ans < 60) ans += 12*60;
		int jam = ans/60;
		int menit = ans%60;
		pf("%d%d:%d%d\n",jam/10,jam%10,menit/10,menit%10);
	}
	
	return 0;
}
