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

bool subs[20005][15];
int notif[15];
int occ[20005];

int main(void)
{
	int n, m, k, i, j, ans = 0;
	memset(notif,0,sizeof(notif));
	memset(occ,0,sizeof(occ));
	sf("%d %d %d", &n, &m, &k);
	FOR(i,1,n)
		FOR(j,1,m)
			sf("%d", &subs[i][j]);
	while(k--) {
		sf("%d %d", &i, &j);
		occ[i]++;
		notif[j]++;
	}
	FOR(i,1,n) {
		ans = 0;
		FOR(j,1,m)
			if(subs[i][j])
				ans += notif[j];
		pf("%d ", ans - occ[i]);
	} nl;
	return 0;
}