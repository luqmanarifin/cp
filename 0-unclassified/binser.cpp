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
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

int main(void)
{
	int a[10] = {0, 0, 1, 2, 3, 6, 8, 10, 13, 15};
	int l = 0, r = 9, n, i;
	sf("%d",&n);
	while(l < r) {
		int mid = (l + r)/2;
		if(a[mid] < n) l = mid + 1;
		else r = mid;
	}
	pf("%d\n",l);
	FORS(i, 10) pf("%d ",a[i]); nl;
	FORS(i, 10) pf("%d ",i); nl;
	
	return 0;
}