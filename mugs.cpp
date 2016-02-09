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
	int i, x, n, s, maks = 0, sum = 0;
	sf("%d %d", &n, &s);
	FORS(i,n) {
		sf("%d", &x);
		sum += x;
		maks = max(maks, x);
	}
	//cout << sum << endl;
	if(sum - maks <= s) puts("YES");
	else puts("NO");
	return 0;
}