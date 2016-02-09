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
#define pb push_back
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int MAX = 100005;
typedef pair<int,bool> pat;
typedef vector<pat> vpat;

vpat adj[MAX];
int i,n,a,c,b;

int main(void)
{
	cin>>n;
	FORS(i,n-1) {
		sf("%d%d",&a,&b,&c);
		adj[a].pb(mp( b,(c==2)) );
		adj[b].pb(mp( a,(c==2)) );
	}
	
	
	return 0;
}