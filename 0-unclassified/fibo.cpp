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

const LL N = 10000000000000;
const LL lim = 100000000;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

LL n, ans;
LL a = 1, b = 1, i = 2;

LL f(LL n){
	if(n == 1) return 1;
	i++;
	if(i%2==1) a = a + b % N;
	else b = b + a % N;
	if(a == n || b == n) return i;
	else if(i > lim) return -1;
	f(n);
}

int main()
{
	cin >> n;
	ans = f(n);
	cout << ans << endl;
	return 0;
}