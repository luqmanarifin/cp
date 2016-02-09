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

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int v, h, i, j, n;
LL ans = 0, dp[505][505];
bool a[505][505];

LL find(int x, int y){
	if(x == v || y == h + 1 || y == 0) return 0; // koordinat tidak valid
	if(!a[x+1][y]) return find(x+1,y); // bawah bolong, meluncur aja
	if(dp[x][y]) return dp[x][y]; // sudah di memo
	
	int kanan = y, kiri = y, m;
	LL sumkanan, sumkiri;
	
	while(a[x+1][kiri]) kiri--; // nyari tempat buat ngeluncur ke kiri
	sumkiri = find(x+1,kiri); // nyari gemericik akibat pantulan ke kiri
	
	while(a[x+1][kanan]) kanan++; // nyari tempat buat ngeluncur ke kanan
	sumkanan = find(x+1,kanan); // nyari gemericik akibat pantulan ke kanan
	
	FOR(m,kiri+1, kanan-1)
		dp[x][m] = 1 + sumkiri + sumkanan; // memoizing
	
	return dp[x][y];
}

int main(void)
{
	sf("%d %d %d", &v, &h, &n);
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	while(n--) {
		int v1, h1, v2, h2;
		sf("%d %d %d %d", &v1, &h1, &v2, &h2);
		FOR(i,h1,h2) a[v1][i]++;
	}
	FOR(i,1,h) 
		ans = max(ans, find(0,i));
		
	cout << ans << endl;
	nl; pf("Grafik Batu : "); nl;
	FOR(i,1,v) { FOR(j,1,h) pf("%d",a[i][j]); nl; }
	nl; pf("Isi Array DP : "); nl;
	FOR(i,1,v) { FOR(j,1,h) pf("%d",dp[i][j]); nl; }

	return 0;
}