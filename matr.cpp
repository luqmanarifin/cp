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

#define nl cout << endl
#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)
#define mp make_pair

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

long n, m, x, y, z, p, nn, mm, k, kk;
pair <long, long> a;

pair<long,long> putar(int kode) {
	if(kode == 0) return a;
	if(kode == 1) return mp(a.second, nn+1-a.first);
	if(kode == 2) return mp(nn+1-a.first, mm+1-a.second);
	if(kode == 3) return mp(mm+1-a.second, a.first);
}

int main()
{
	sf("%ld %ld %ld %ld %ld %ld", &n, &m, &x, &y, &z, &p);
	long i;
	FORS(i,p) {
		nn = n, mm = m;
		sf("%ld %ld", &k, &kk);
		a = make_pair(k, kk);
		
		a = putar(x%4);
		if(x%4 == 1 || x%4 == 3) swap(nn, mm);
		
		if(y%2) a.second = mm+1-a.second;
		
		a = putar((4 - z%4)%4);
		pf("%d %d\n", a.first, a.second);
	}
	return 0;
}