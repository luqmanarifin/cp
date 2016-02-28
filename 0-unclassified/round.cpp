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
const int inf = 0x7FFFFFFF;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

int faktor(int a, int b) {
	if(a % b || !a) return 0;
	return 1 + faktor(a/b, b);
}

int dua[1005][1005], lima[1005][1005], posNol = 0;
string Dua[1005], Lima[1005];
bool nolDua[1005][1005], nolLima[1005][1005];

int main(void)
{
	int n, i, j;
	FORS(i,1005) dua[i][0] = lima[i][0] = dua[0][i] = lima[0][i]= inf;
	
	sf("%d", &n);
	FOR(i,1,n)
		FOR(j,1,n) {
			int x; sf("%d", &x);
			if(!x) {
				posNol = i;
				nolDua[i][j] = nolLima[i][j] = 1;
			}
			dua[i][j] = faktor(x, 2);
			lima[i][j] = faktor(x, 5);
		}
		
	FOR(i,1,n)
		FOR(j,1,n) {
			if(i == 1 && j == 1) continue;
			if(dua[i-1][j] < dua[i][j-1]) {
				dua[i][j] += dua[i-1][j];
				Dua[j] = Dua[j] + 'D';
				if(nolDua[i-1][j]) nolDua[i][j] = 1;
			} else {
				dua[i][j] += dua[i][j-1];
				Dua[j] = Dua[j-1] + 'R';
				if(dua[i-1][j] > dua[i][j-1])
					if(nolDua[i][j-1])
						nolDua[i][j] = 1; 
			}
			if(lima[i-1][j] < lima[i][j-1]) {
				lima[i][j] += lima[i-1][j];
				Lima[j] = Lima[j] + 'D';
				if(nolLima[i-1][j]) nolLima[i][j] = 1;
			} else {
				lima[i][j] += lima[i][j-1];
				Lima[j] = Lima[j-1] + 'R';
				if(lima[i-1][j] > lima[i][j-1])
					if(nolLima[i][j-1])
						nolLima[i][j] = 1;
			}
		}
		
	int ans = min(dua[n][n], lima[n][n]);
	if(ans && posNol) {
		NOL:;
		puts("1");
		FORS(i,posNol-1) pf("D");
		FORS(i,n-1) pf("R");
		FOR(i,posNol+1,n) pf("D"); nl;
		return 0;
	}
	if(dua[n][n] < lima[n][n]) {
		if(nolDua[n][n]) goto NOL;
		cout << dua[n][n] << endl;
		cout << Dua[n] << endl;
	} else {
		if(nolLima[n][n]) goto NOL;
		cout << lima[n][n] << endl;
		cout << Lima[n] << endl;
	}
	
	return 0;
}
