#include <iostream>
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

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)

const int N = 100000;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

LL n, i, a[N], b[N];
int main()
{
	sf("%ld",&n);
	FORS(i,n) sf("%ld",&a[i]);
	FORS(i,n) sf("%ld",&b[i]);
	LL ans = 0;
	FORS(i,n){
		if(((b[i]%2 == 0)&&(a[i] < b[i]/2))||((b[i]%2 == 1)&&(a[i] < (b[i]+1)/2))|| b[i]==1) ans--;
		else if(b[i]%2 == 0) ans += (b[i]/2)*(b[i]/2);
		else ans += ((b[i]+1)/2)*((b[i]-1)/2);
	}
	cout << ans << endl;
	return 0;
}