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

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a, b); }

struct Kolom {
	int dua, lima;
	string ans;
};

int a[1005][1005];
bool nol[1005][1005];
Kolom dp[1005][1005];

int faktor(int a, int b) {
	if(a % b || !a) return 0;
	return 1 + faktor(a/b, b);
}

int main(void)
{
	int n, i, j;
	reset(nol, 0);
	sf("%d", &n);
	FOR(i,1,n)
		FOR(j,1,n) {
			sf("%d", &a[i][j]);
			if(!a[i][j]) nol[i][j] = 1;
			dp[i][j].dua = faktor(a[i][j], 2);
			dp[i][j].lima = faktor(a[i][j], 5);
			if(i == 1 && j == 1) continue;
			if(i == 1) {
				dp[i][j].dua += dp[i][j-1].dua;
				dp[i][j].lima += dp[i][j-1].lima;
				dp[i][j].ans = dp[i][j-1].ans + 'R';
				if(nol[i][j-1]) nol[i][j] = 1;
			}
			if(j == 1) {
				dp[i][j].dua += dp[i-1][j].dua;
				dp[i][j].lima += dp[i-1][j].lima;
				dp[i][j].ans = dp[i-1][j].ans + 'D';
				if(nol[i-1][j]) nol[i][j] = 1;
			}
		}
	
	FOR(i,2,n) 
		FOR(j,2,n) {
			int atas = min(dp[i][j].dua + dp[i-1][j].dua, dp[i][j].lima + dp[i-1][j].lima);
			int kiri = min(dp[i][j].dua + dp[i][j-1].dua, dp[i][j].lima + dp[i][j-1].lima);
			int atasTot = dp[i][j].dua + dp[i-1][j].dua + dp[i][j].lima + dp[i-1][j].lima;
			int kiriTot = dp[i][j].dua + dp[i][j-1].dua + dp[i][j].lima + dp[i][j-1].lima;
			double Kiri = (nol[i][j-1]? 0.5 : kiri);
			double Atas = (nol[i-1][j]? 0.5 : atas);
			if(Atas < Kiri || (Atas == Kiri && atasTot < kiriTot)) {
				dp[i][j].dua += dp[i-1][j].dua;
				dp[i][j].lima += dp[i-1][j].lima;
				dp[i][j].ans = dp[i-1][j].ans + 'D';
				if(nol[i-1][j]) nol[i][j] = 1;
			} else {
				dp[i][j].dua += dp[i][j-1].dua;
				dp[i][j].lima += dp[i][j-1].lima;
				dp[i][j].ans = dp[i][j-1].ans + 'R';
				if(nol[i][j-1]) nol[i][j] = 1;
			}
		}
	if(nol[n][n]) puts("1");
	else cout << min(dp[n][n].dua, dp[n][n].lima) << endl;
	cout << dp[n][n].ans << endl;
	/*
	FOR(i,1,n) { FOR(j,1,n) cout << dp[i][j].ans << ' '; nl; }
	FOR(i,1,n) { FOR(j,1,n) pf("%d ", dp[i][j].dua + dp[i][j].lima); nl; }
	*/
	return 0;
}
