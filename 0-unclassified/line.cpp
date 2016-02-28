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
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)

const LL N = 100001;
const LL gede = 100000000000;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

LL n, d, i, j, x[N], ans = 0;

int main()
{
	cin >> n >> d;
	FOR(i,1,n) sf("%I64d", &x[i]);
	if(n <= 2) { cout << 0 << endl; return 0; }
	j = n + 1; i = n - 2;
	do{
		j--; if(j - 2 < i) i = j - 2;
		while(x[j] - x[i] <= d && 0 < i) i--; i++;
		if(x[j] - x[i] <= d) ans += (j-i-1)*(j-i)/2;
	} while(j > 3);
	
	cout << ans << endl;
	return 0;
}