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
#define open freopen("input.txt","r",stdin); freopen("input.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

LL num[100];
LL pre[100];

int main(void)
{
	ios_base::sync_with_stdio(false);
	open;
	int i, j;
	num[0] = 1;
	FOR(i,1,63)
		num[i] = num[i-1]*2;
	int t = 50000, sign = 1;
	while(t--) {
		LL cur = 0;
		bool done[100];
		memset(done, 0, sizeof(done));
		int now = rand() % 64;
		FORS(i, 32) {
			while(done[now]) now = rand() % 64;
			done[now] = 1;
		}
		FORS(i, 64)
			if(done[i])
				cur ^= num[i];
		cur *= 1LL*sign;
		sign *= -1;
		cout << cur << endl;
	}
	close;
	return 0;
}