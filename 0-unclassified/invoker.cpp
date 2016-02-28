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

int a[100], b[100], t, m;

LL c(int n, int k) {
	LL temp = 1;
	int p[32], q[32];
	int i,j;
	FORS(i,k){
		p[i] = n - i;
		q[i] = i + 1;
	}
	i = 0;
	while(i < k) {
		j = 0;
		while(j < k && q[i] != 1) {
			LL fpb = gcd(p[j],q[i]);
			p[j] /= fpb;
			q[i] /= fpb;
			j++;
		}
		i++;
	}
	FORS(i,k) temp *= p[i];
	return temp;
}

int main()
{
	sf("%d", &m);
	FORS(t,m) sf("%d%d", &a[t], &b[t]);
	FORS(t,m) { cout << c(a[t]+b[t]-1, b[t]); nl; }
	return 0;
}