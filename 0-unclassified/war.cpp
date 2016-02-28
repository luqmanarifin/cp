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
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("D-large-practice.in","r",stdin); freopen("D-large-practice.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

DB naomi[1010], ken[1010];

int main(void)
{
	open;
	int t,i,n,j,a,b,x,y;
	sf("%d", &t);
	FOR(i,1,t) {
		sf("%d", &n);
		memset(naomi,0,sizeof(naomi));
		memset(ken,0,sizeof(ken));
		a = 0; b = 0;
		FORS(j,n) cin >> naomi[j]; sort(naomi,naomi+n);
		FORS(j,n) cin >> ken[j]; sort(ken,ken+n);
		x = n-1; y = n-1;
		while(x >= 0 && y >= 0) {
			while(naomi[x] <= ken[y] && y >= 0) y--;
			if(naomi[x] > ken[y] && y >= 0) a++;
			x--; y--;
		}
		x = n-1; y = n-1;
		while(x >= 0 && y >= 0) {
			while(naomi[y] >= ken[x] && y >= 0) y--;
			if(naomi[y] < ken[x] && y >= 0) b++;
			x--; y--;
		}
		pf("Case #%d: %d %d\n",i,a,n-b);
	}
	close;
	
	return 0;
}