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

int t[105];

int main(void)
{
	int n, m, mini, maks, i, x, need = 0;
	sf("%d %d %d %d", &n, &m, &mini, &maks);
	memset(t,0,sizeof(t));
	FORS(i,m) {
		sf("%d", &x);
		t[x]++;
		if(x > maks || x < mini) {
			puts("Incorrect");
			return 0;
		}
	}
	if(!t[mini]) need++;
	if(!t[maks]) need++;
	if(need > n-m) puts("Incorrect");
	else puts("Correct");
	
	return 0;
}