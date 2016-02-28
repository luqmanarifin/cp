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
#include <stdlib.h>

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

const int N = 300005;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

struct tipe {
	long rating;
	long init;
};

bool sortByRating (const tipe &l, const tipe &r) {
	return l.rating < r.rating;
}

bool sortByInit (const tipe &l, const tipe &r) {
	return l.init < r.init;
}

long n,i;
tipe a[N];

int main()
{
	sf("%ld",&n);
	FORS(i,n) {
		sf("%ld",&a[i].rating);
		a[i].init = i;
	}
	sort(a, a+n, sortByRating);
	FOR(i,1,n-1)
		if(a[i-1].rating >= a[i].rating)
			a[i].rating = a[i-1].rating + 1;
	sort(a, a+n, sortByInit);
	FORS(i,n) pf("%d ",a[i].rating); nl;
	return 0;
}