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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int waktu[10];

int main(void)
{
	int m, n, i, j, x;
	memset(waktu, 0, sizeof(waktu));
	sf("%d %d", &m, &n);
	FOR(i,1,n) {
		sf("%d", &x);
		waktu[i] = waktu[i-1] + x;
	} pf("%d ", waktu[n]);
	
	FOR(i,1,m-1) {
		FOR(j,1,n) {
			sf("%d", &x);
			waktu[j] = max(waktu[j],waktu[j-1]) + x;
		}
		pf("%d ", waktu[n]);
	}
	nl;
	
	return 0;
}