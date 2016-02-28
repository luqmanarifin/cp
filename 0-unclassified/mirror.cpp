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

const int inf = 105;

bool a[105][105];
int ans = inf;
int n, m, i, j, t;

bool isMirror(int row) {
	int i, j;
	FOR(i,1,row) FOR(j,1,m) if(a[i][j] != a[row*2+1-i][j]) return 0; 
	return 1;
}

int main(void)
{
	
	sf("%d %d", &n, &m); t = n;
	FOR(i,1,n) FOR(j,1,m) sf("%d", &a[i][j]);
	while(true) {
		bool temp = 1; int k = t;
		while(k < n) {
			if(!isMirror(k)) { temp = 0; break; }
			k *= 2;
		}
		if(temp) ans = t;
		if(t%2) break;
		t /= 2;
	}
	if(ans == inf) ans = n;
	cout << ans << endl;
	
	return 0;
}