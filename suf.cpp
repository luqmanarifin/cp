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

const int N = 1000010;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

long n,m,i;
long a[N], l[N], t[N], ans[N];

int main()
{
	cin >> n >> m;
	FORS(i,n) sf("%d", &a[i]);
	ans[n] = 0;
	FORD(i,n){
		if(t[a[i]] == 0) ans[i] = ans[i+1] + 1;
		else ans[i] = ans[i+1];
		t[a[i]] = 1;
	}
	FORS(i,m) sf("%d",&l[i]);
	FORS(i,m) pf("%d\n", ans[l[i]-1]);
	return 0;
}