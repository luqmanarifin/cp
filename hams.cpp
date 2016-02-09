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
	int ans[105], n, a, b;
	cin >> n >> a >> b;
	while(a--) {
		int x; cin >> x;
		ans[x] = 1;
	}
	while(b--) {
		int x; cin >> x;
		ans[x] = 2;
	}
	int i;
	FOR(i,1,n) pf("%d ", ans[i]); nl;
	return 0;
}