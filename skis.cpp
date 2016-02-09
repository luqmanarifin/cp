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

int n,q,i,a[1000006],temp;
LL ans = 0;

int main()
{
	sf("%d%d",&n,&q);
	FOR(i,1,n){ sf("%d",&temp); a[temp]++; }
	if(q%2 == 0){
		FOR(i,1,q/2-1) ans += min(a[i],a[q-i]);
		ans += a[q/2]/2;
	}
	else
		FOR(i,1,q/2) ans += min(a[i],a[q-i]);
		
	pf("%d\n",ans);
	return 0;
}