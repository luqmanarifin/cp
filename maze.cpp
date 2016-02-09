#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const int N = 505;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

char temp[N];
char a[N][N];
int n, m, k, i, j;

void dfs(int x, int y){
	if((x <= 0)||(x > n)||(y <= -1)||(y > m-1)||(a[x][y] != '.')) return;
	a[x][y] = 'L';
	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
	if(k == 0) return;
	a[x][y] = 'X';
	k--;
}

int main()
{
	sf("%d %d %d", &n, &m, &k);
	FOR(i,1,n)
		sf("%s",&a[i]);
	FOR(i,1,n)
		FOR(j,1,m)
			if(a[i][j] == '.')
				dfs(i,j);
	FOR(i,1,n) {
		FOR(j,0,m-1) {
			if(a[i][j] == 'L') putchar('.');
			else putchar(a[i][j]);
		}
		nl;
	}		
	return 0;
}