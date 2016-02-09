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
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

bool nyala[105];
int ans[105];

int main(void)
{
	int n, m, i;
	sf("%d %d", &n, &m);
	FOR(i, 1, n) nyala[i] = 1;
	FOR(i, 1, m) {
		int temp, j; sf("%d", &temp);
		FOR(j, temp, n) {
			if(nyala[j]) {
				ans[j] = temp;
				nyala[j] = 0;
			}
		}
	}
	FOR(i,1,n) pf("%d ", ans[i]); nl;
	
	return 0;
}