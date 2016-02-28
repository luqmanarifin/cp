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

LL s(LL x){
	LL a = x % 10;
	if(x == a) return a;
	return a + s((x-a)/10);
}

LL awal, akhir, i, n;

int main()
{

	cin >> n;
	akhir = ceil(sqrt(n));
	awal = (trunc(sqrt(153*153 + 4*n)) - 153) / 2;
	// cout << awal << " " << akhir << endl;
	FOR(i,awal,akhir)
		if(i*(i + s(i)) == n) { cout << i << endl; return 0; }
	cout << -1 << endl;
	return 0;
}