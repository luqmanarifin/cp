#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define DB double
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for((i) = (a); (i) <= (b); ++(i))
#define FORD(i,a,b) for((i) = (a); (i) >= (b); --(i))
#define FORS(i,n) for((i) = 0; (i) < (n); ++(i))
#define FORM(i,n) for((i) = (n) - 1; (i) >= 0; --(i))
#define reset(cok, n) memset(cok, (n), sizeof(cok))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

int main(void)
{
	char x[10000]; int n, i;
	gets(x); int k = strlen(x);
	FORS(i,k) if(x[i] == ' ') n++;
	if(n%2) puts("TIDAK");
	else puts("YA");
	
	return 0;
}