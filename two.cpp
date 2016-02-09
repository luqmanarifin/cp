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
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)
#define mp make_pair

const long N = 2*1e7 + 1;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

int t, sum = 0, i, tmp;
long pol;
map<int, int> a;

void tambah(long n) {
	if(a[n]) {
		a.erase(n);
		tambah(n+1);
	} else {
		a[n]++;
		pol = max(pol, n);
	}	
}

int main()
{
	sf("%d", &t);
	FORS(i,t) {
		sf("%ld", &tmp);
		tambah(tmp);
	}
	cout << pol + 1 - a.size(); nl;
	return 0;
}