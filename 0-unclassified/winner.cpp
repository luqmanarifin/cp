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
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORD(i,n) FORM(i, 0, n-1)
#define mp make_pair

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

map<string, int> f, g;
int n, c[1010], maks = 0, i;
string s[1010];

int main()
{
	cin >> n;
	FORS(i,n) {
		cin >> s[i] >> c[i];
		f[s[i]] += c[i];
	}
	FORS(i,n) maks = max(maks, f[s[i]]);
	FORS(i,n) {
		g[s[i]] += c[i];
		//cout << h[s[i]] << " " << s[i] << " " << g[s[i]]<<" "<<maks; nl;
		if(f[s[i]] == maks && g[s[i]] >= maks) {
			cout << s[i] << endl;
			break;
		}
	}
	return 0;
}