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

int a[1000006], b[1000006], p, x, i;

int find(int p) {
	int rem = a[p] - a[1]*x;
	FOR(i,2,p-1){
		a[i] = (rem*10 + a[i-1])/x;
		// pf("%d %d\n",i,a[i]);
		if(x*a[i] == 0)
			rem = rem*10 + a[i-1];
		else
			rem = (rem*10 + a[i-1])%(x*a[i]);
	}
	// pf("%d\n",rem);
	if((rem*10+a[p-1])%x) return -1;
	return (rem*10+a[p-1])/x;
}

int main()
{
	cin >> p >> x;
	a[1] = 1;
	a[p] = a[1] * x;
	while(a[1] * x < 10) {
		a[0] = a[p];
		// pf("%d %d\n",find(p),a[p]);
		if(find(p) == a[p]) { FOR(i,1,p) cout << a[i]; nl; return 0; }
		if(a[p] < 9) a[p]++;
		else a[1]++;
	}
	cout << "Impossible"; nl;
	return 0;
}