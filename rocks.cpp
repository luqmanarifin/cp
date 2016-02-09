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

int n,x,i,j;

int main()
{
	sf("%d %d", &n, &x);
	if(n == 5) pf(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1\n");
	else if (n == 3) pf(">vv\n^<.\n^.<\n1 3\n");
	else {
		FORS(i,34) pf(">"); FORS(i,32) pf(".>"); pf("v."); nl;
		pf("^v"); FORS(i,32) pf("<."); FORS(i,33) pf("<"); pf("."); nl;
		FORS(j,48){
			pf("^"); FORS(i,33) pf(">"); FORS(i,32) pf(".>"); pf("v."); nl;
			pf("^v"); FORS(i,32) pf("<."); FORS(i,33) pf("<"); pf("."); nl;
		}
		pf("^"); FORS(i,33) pf(">"); FORS(i,32) pf(".>"); pf("v."); nl;
		pf("^."); FORS(i,32) pf("<."); FORS(i,33) pf("<"); pf("."); nl;
		pf("1 1"); nl;
	}
	return 0;
}