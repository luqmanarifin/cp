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

int main(void)
{
	int n, m, k, t;
	sf("%d %d %d", &n, &m, &k);
	
	int i = 1, j = 0;
	FORS(t, k-1) {	
		if((j == 1 && !(i&1)) || (j == m && i&1)) i++;
		else if(i&1) j++;
		else j--;
		pf("2 %d %d ", i, j);
		
		if((j == 1 && !(i&1)) || (j == m && i&1)) i++;
		else if(i&1) j++;
		else j--;
		pf("%d %d\n", i, j);
	} 
	int remain = n*m - 2*(k-1);
	pf("%d ", remain);
	FORS(t, remain) {
		if((j == 1 && !(i&1)) || (j == m && i&1)) i++;
		else if(i&1) j++;
		else j--;
		pf("%d %d ", i, j);
	} nl;
	
	return 0;
}
