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

#define nl cout << endl
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

int a[1000], pos[1000], posbenar[1000];
int n,ans,i,target,j=0;

int find(int n){
	FORS(i,n)
		if (pos[a[i]] != posbenar[a[i]])
			return a[i];
	return N;
}

int main()
{
	sf("%d",&n);
	while(n != 0) {
		ans = 0; j++;
		FORS(i,n) {
			sf("%d",&a[i]);
			pos[a[i]] = i;
			// pf("%d\n",i);
		}
		sort(a,a+n);
		FORS(i,n) posbenar[a[i]] = i;
		target = find(n);
		while(target != N) {
			while(pos[target] != posbenar[target]) {
				// pf("%d %d\n",target,a[pos[target]]);
				ans = ans + target + a[pos[target]];
				swap(pos[target],pos[a[pos[target]]]);
			}
			target = find(n);
		}
		pf("Case %d: %d",j,ans); nl; nl;
		sf("%d",&n);
	}
	return 0;
}