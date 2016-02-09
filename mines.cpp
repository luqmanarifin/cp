#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;
const LL mod = 1e9 + 7;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

char mines[N];
LL dp[N][5];

void fill (int i, int stat) {
	switch(stat) {
	case 0:	dp[i+1][0] += dp[i][0]; dp[i+1][0]%=mod; // kasus di tempat isinya 0
				dp[i+1][1] += dp[i][0]; dp[i+1][1]%=mod;
			break;
	case 1:	dp[i+1][0] += dp[i][2]; dp[i+1][0]%=mod; // kasus di tempat isinya 1
				dp[i+1][1] += dp[i][2]; dp[i+1][1]%=mod;
				dp[i+1][4] += dp[i][1]; dp[i+1][4]%=mod;
			break;
	case 2: 	dp[i+1][4] += dp[i][3]; dp[i+1][4]%=mod; // kasus di tempat isinya 2
			break;
	case 3: 	dp[i+1][2] += dp[i][4]; dp[i+1][2]%=mod; // kasus di tempat isinya BOM DUARRR!
				dp[i+1][3] += dp[i][4]; dp[i+1][3]%=mod;
				dp[i+1][4] += dp[i][4]; dp[i+1][4]%=mod;
			break;
	}
}
/*
	kode array dp :
		0 -> banyak jalan bila diisi nol
		1 -> banyak jalan bila diisi 'satu' dengan bom depan
		2 -> banyak jalan bila diisi 'satu' dengan bom blkg
		3 -> banyak jalan bila diisi 'dua'
		4 -> banyak jalan bila diisi bom
*/
int main () {
	int i,j;
	gets(mines); int len=strlen(mines);
	memset(dp, 0, sizeof(dp));
	
	/* DP bottom-up */

	dp[0][0] = dp[0][1] = dp[0][4] = 1LL;	//valid config in first cell
	FOR(i,0,len-2)
		switch (mines[i]) {	
			case '0':fill(i,0); break;
			case '2':fill(i,2); break;
			case '*':fill(i,3); break;
			case '1':fill(i,1); break;
			case '?':FOR(j,0,3) fill(i,j); break;
		}
	
	LL ans=0;
	switch (mines[len-1]) {	
		case '0':	ans = dp[len-1][0]; break;
		case '*':	ans = dp[len-1][4]; break;
		case '1':	ans = dp[len-1][2]; break;
		case '?':	FOR(j,0,4) if (j%2==0) ans += dp[len-1][j];
				break;
	}
	//FOR(i,0,4) cout<<dp[len-1][i]<<' '; nl;
	printf("%I64d", ans%mod );
   return 0;
	
}