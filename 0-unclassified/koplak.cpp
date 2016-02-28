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

map<int,bool> ada[30005];
int ans[30005];

int main(void)
{
	int a, b, n, m, i, j;
	sf("%d %d", &n, &m);
	while(m--) {
		sf("%d %d", &a, &b);
		ada[a][b] = true;
	}
	FOR(i,1,n) ans[i] = i;
	random_shuffle(ans+1, ans+1+n); 
	
	bool masih = 1;
	while(masih) {
		masih = 0;
		FOR(i,1,n-1)
			if(ada[ans[i]][ans[i+1]]) {
				swap(ans[i], ans[i+1]);
				masih = true;
			}
	}
	FOR(i,1,n) pf("%d ", ans[i]); nl;
	
	return 0;
}