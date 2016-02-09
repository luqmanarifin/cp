/*
ID: l.arifi1
PROG: test
LANG: C++
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
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
#include <cassert>

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
#define open freopen("a2.in","r",stdin); freopen("a2.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	ios_base::sync_with_stdio(false);
	open;
	int t;
	cin >> t;
	while(t--) {
		string p, q;
		cin >> p >> q;
		int pp = p.length(), j;
		int qq = q.length(), i;
		FORS(i, pp) {
			if(i == qq || p[i] != q[i]) break;
		}
		if(qq - i + pp - i < 1 + pp) {
			FORS(j, qq-i) cout << '<';
			FOR(j, i, pp-1) cout << p[j];
			cout << '*' << endl;
		} else cout << '*' << p << '*' << endl;
	}
	
	close;
	return 0;
}