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
#define open freopen("A-large-practice.in","r",stdin); freopen("A-large-practice.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

map<LL, LL> need;
map<LL, bool> done;

bool check(LL r, LL c, LL t) {
	LL a = r*4 + c*4 - 2;
	return (double)a * double(c) < 9e18 && a*c/2 <= t;
}

int main(void)
{
	//open;
	int T, n;
	LL r, t;
	sf("%d", &T);
	FOR(n,1,T) {
		sf("%lld %lld", &r, &t);
		LL lef = 1, rig = t/r;
		while(lef < rig) {
			LL mid = (lef + rig + 1)/2;
			if(check(r, mid, t))
				lef = mid;
			else
				rig = mid - 1;
		}
		pf("Case #%d: %I64d\n",n,lef);
	}
	//close;
	
	return 0;
}