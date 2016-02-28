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
#include <iomanip>

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
#define open freopen("B-large-practice.in","r",stdin); freopen("B-large-practice.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000100;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

DB time[100010];
DB c, f, x, ans;

int main(void)
{
	open;
	int t, i, j, k;
	sf("%d", &t);
	FOR(i,1,t) {
		memset(time, 0, sizeof(time));
		cin >> c >> f >> x;
		DB cookie = 2.00, ans = 1e5;
		FOR(j,0,1000) {
			cookie = 2;
			FOR(k,1,j) {
				time[j] += (DB) c/cookie;
				cookie += f;
			}
			time[j] += (DB) x/cookie;
			ans = fmin(ans, time[j]);
		}
		pf("Case #%d: %.7f\n",i,ans);
		cout.precision(7);
		cerr.precision(7);
		cout << "Case #" << i << ": " << << ans << endl;
		cerr << "Case #" << i << ": " << ans << endl;
	}
	close;
	
	return 0;
}