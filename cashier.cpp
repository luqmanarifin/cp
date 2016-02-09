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

const LL N = 1e17;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int item[105];
LL ans = N;

int main(void)
{
	int n,i,j;
	sf("%d", &n);
	FOR(i,1,n) sf("%d", &item[i]);
	FOR(i,1,n) {
		LL sum = 0;
		FOR(j,1,item[i]) {
			int temp;
			sf("%d", &temp);
			sum += temp;
		}
		sum = sum*5 + item[i]*15;
		ans = min(ans, sum);
	}
	cout << ans << endl;
	
	return 0;
}