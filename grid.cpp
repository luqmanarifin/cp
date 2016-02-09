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
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define mp make_pair

const LL mod = 1e9 + 7;
const LL inf = 4e18;
const int N = 405;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int n, m, hor[N][N], ver[N][N], diag[N][N], a[N][N];
int ans = 0;

void putar(void) {
	int temp[N][N], i , j;
	FORS(i,n)
		FORS(j,m)
			temp[j][n-i-1] = a[i][j];
			
	FORS(i,m)
		FORS(j,n)
			a[i][j] = temp[i][j];
			
	swap(n,m);
}

int kaki(int k, int l) {
	int cur = 0, r = 1;
	while(ver[k + 2*r][l] == ver[k][l] && !a[k+r][l+r] && k + 2*r < n && l + r < m) {
		if(diag[k+r][l+r] == diag[k+2*r][l]) cur++;
		r++;
	}
	return cur;
}

int siku(int k, int l) {
	int cur = 0;
	int kk = k+1, ll = l+1;
	while(!a[kk][l] && !a[kk][ll] && kk < n && ll < m) {
		if(hor[kk][l-1] == hor[kk][ll]) cur++;
		kk++; ll++;
	}
	return cur;
}

void do_it(void){
	reset(hor, 0);
	reset(ver, 0);
	reset(diag, 0);
	int i, j;
	FORS(i,n)
		FORS(j,m)
			hor[i][j] = hor[i][j-1] + a[i][j];
			
	FORS(i,n)
		FORS(j,m)
			ver[i][j] = ver[i-1][j] + a[i][j];
			
	FORS(i,n)
		FORS(j,m)
			diag[i][j] = diag[i-1][j+1] + a[i][j];
			
	FORS(i,n)
		FORS(j,m)
			if(!a[i][j])
				ans += kaki(i,j) + siku(i,j);
}

int main(void)
{
	sf("%d %d", &n, &m);
	
	int i, j, l;
	FORS(i,n) {
		char x[405];
		sf("%s", x);
		FORS(j,m) {
			a[i][j] = x[j] - '0';
		}
	}
	
	FORS(i,4) {
		putar();
		do_it();
	}
	
	pf("%d\n", ans);
	return 0;
}
