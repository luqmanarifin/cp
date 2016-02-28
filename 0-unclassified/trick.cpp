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
#define open freopen("A-small-practice.in","r",stdin); freopen("A-small-practice.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int card[20];

int main(void)
{
	open;
	int n, i, x, j, ans, t, cnt; sf("%d", &n);
	FOR(i,1,n) {
		memset(card, 0, sizeof(card));
		sf("%d", &x);
		FORS(j,16) {
			sf("%d", &t);
			if(j/4 == x-1)
				card[t]++;
		}
		sf("%d", &x);
		FORS(j,16) {
			sf("%d", &t);
			if(j/4 == x-1)
				card[t]++;
		}
		cnt = 0;
		FOR(j,1,16)
			if(card[j] == 2) {
				cnt++;
				ans = j;
			}
		pf("Case #%d: ", i);
		if(cnt > 1) puts("Bad magician!");
		else if(cnt == 0) puts("Volunteer cheated!");
		else pf("%d\n", ans);
	}
	close;
	
	return 0;
}