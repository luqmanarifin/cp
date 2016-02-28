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

const LL mod = 1e9+7;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

char a[55][55];
int n, t;

void inc() {
	int x, y;
	FORS(x,n)
		FORS(y,n) {
			if(a[x][y] == '9') a[x][y] = '0';
			else
				a[x][y] = (char) ((int) a[x][y] + 1);
		}
}

void trans() {
	int x, y; char b[55][55];
	FORS(x,n)
		FORS(y,n)
			b[y][x] = a[x][y];
	memcpy(a, b, sizeof(b));
}

void row(int m, int l) {
	int y; FORS(y,n) swap(a[m][y], a[l][y]);
}

void col(int m, int l) {
	int x; FORS(x,n) swap(a[x][m], a[x][l]);
}

int main(void)
{
	int i, k, l, m;
	sf("%d", &t);
	FOR(i,1,t) {
		sf("%d", &n);
		reset(a,'*');
		FORS(k,n) sf("%s", a[k]);
		
		char test[15];
		int nambah = 0, x;
		sf("%d", &x);
		while(x--) {
			cin >> test;
			switch(test[0]) {
				case 'i' : nambah++; break;
				case 'd' : nambah--; break;
				case 't' : trans(); break;
				case 'c' :
					sf("%d %d", &m, &l);
					col(m-1, l-1);
					break;
				case 'r' :
					sf("%d %d", &m, &l);
					row(m-1, l-1);
					break;
			}
		}
		nambah %= 10;
		if(nambah < 0) nambah += 10;
		while(nambah--) inc();
		
		pf("Case #%d\n",i);
		FORS(k,n) { FORS(l,n) putchar(a[k][l]); nl; }
		nl;
	}
	
	return 0;
}