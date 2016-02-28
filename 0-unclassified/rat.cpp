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
#define reset(cok,n) memset(cok, n, sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

int main(void)
{
	int a[105], n, i;
	sf("%d", &n);
	FOR(i,1,n) sf("%d", a + i);
	FOR(i,1,n) {
		if(i == 1) pf("%d ",3*a[i]);
		else if(i == 2) pf("%d ", 3*a[i]+2*a[i-1]);
		else pf("%d ",3*a[i]+2*a[i-1]+a[i-2]);
	}
	nl;
	return 0;
}