#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = b; i >= a; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n-i; i >= 0; --i)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

int main(void)
{
	int i, j, n, k;
	sf("%d %d", &n, &k);
	if((n+1)/2 <= k) {
		puts("-1");
		return 0;
	}
	cout << n*k << endl;
	FOR(i,1,n)
		FOR(j,1,k)
			if(i+j > n) pf("%d %d\n",i,i+j-n);
			else pf("%d %d\n",i,i+j);
	
	return 0;
}