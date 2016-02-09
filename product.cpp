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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db (double)

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int q, i, j, n, kode, th, sum = 0;

int main()
{
	sf("%d", &n);
	FOR(i,1,n) FOR(j,1,n) {
		sf("%d", &th);
		if(i == j) sum += th;
	}
	sf("%d", &q);
	while(q--) {
		sf("%d", &kode);
		if(kode == 3) pf("%d", sum%2);
		else {
			sf("%d", &th);
			sum++;
		}
	}
	nl;
	
	return 0;
}