#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

int main(void)
{
	int n, x, k, done[100005];
	memset(done, -1, sizeof(done));
	sf("%d", &n);
	while(n--) {
		sf("%d %d", &x, &k);
		if(x > done[k] + 1)
			{ puts("NO"); return 0; }
		else if(x == done[k] + 1)
			done[k]++;
	}
	puts("YES");
	
	return 0;
}