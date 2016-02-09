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
#include <sstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <utility>
#include <functional>
#include <cassert>

using namespace std;

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

LL mod;

LL power(LL a, LL b) {
	if(b == 0) return 1LL;
	LL temp = power(a, b/2);
	temp *= temp;
	temp %= mod;
	if(b & 1) {
		temp *= a;
		temp %= mod;
	}
	return temp;
}

LL a[10005];

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//open;
	int tt = 0;
	char s[100];
	gets(s);
	while(s[0] != '#') {
		stringstream ss(s);
		int n, i, j; 
		ss >> mod >> n;
		FORS(i, n) ss >> a[i];
		FORD(i, n-1, 1) {
			a[i-1] = power(a[i-1], a[i]);
		}
		pf("Case #%d: %d\n", ++tt, (int) a[0]);
		gets(s);
	}
	
	//close;
	return 0;
}