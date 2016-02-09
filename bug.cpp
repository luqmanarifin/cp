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
#define init first
#define occ second

const int maxn = 3e5 + 5;

pair<int,int> vote[maxn];
map<pair<int,int>, int> dob;
LL ans = 0;

bool asc(const pair<int,int> &lef, const pair<int,int> &rig) {
	return lef.occ < rig.occ;
}

int main(void)
{
	int n, p, i, j, x, y, t, a, b;
	sf("%d %d", &n, &p);
	FOR(i,1,n) vote[i].init = i;
	FOR(i,1,n) {
		sf("%d %d", &x, &y);
		vote[x].occ++;
		vote[y].occ++;
		if(x > y) swap(x,y);
		dob[mp(x,y)]++;
	}
	
	sort(vote+1,vote+1+n,asc);
	j = n;
	while(vote[j-1].occ + vote[j].occ >= p && j > 1) {
		i = j-1;
		while(vote[i].occ + vote[j].occ >= p && i) {
			//pf("%d %d",i,j); nl;
			a = vote[i].init; b = vote[j].init; if(b < a) swap(a,b);
			if(vote[i].occ+vote[j].occ-dob[mp(a,b)] >= p) ans++;
			i--;
		}
		j--;
	}
		
	cout << ans << endl;
	
	return 0;
}