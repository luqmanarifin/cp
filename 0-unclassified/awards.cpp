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
#define skor second

map<int,bool> ada[30005];
pair<int,int> person[30005];

bool bySkor(const pair<int,int> &lhs, const pair<int,int> &rhs) {
	return lhs.skor < rhs.skor;
}

int main(void)
{
	int n, m, a, b, i;
	sf("%d %d" ,&n, &m);
	while(m--) {
		sf("%d %d", &a, &b);
		ada[a][b] = true;
		person[a].skor++;
		person[a].init = a;
		person[b].skor--;
		person[b].init = b;
	}
	sort(person+1, person+1+n, bySkor);
	FOR(i,1,n-1)
		if(ada[person[i].init][person[i+1].init]) {
			swap(person[i].init, person[i+1].init);
			swap(person[i].skor, person[i+1].skor);
		}
	FOR(i,1,n)
		pf("%d ",person[i].init);
	nl;
	
	return 0;
}