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

int main()
{
	int n;
	scanf("%d",&n);
	if(n == 1) pf("i");
	else if(n == 2) pf("w\nii");
	else if(n == 3) pf("iw\niii\nwi");
	else if(n == 4) pf("iwi\niiii\nwii\nww\niiw");
	else if(n == 5) pf("iwii\niww\niiiw\nwiw\nwiii\nwwi\niiwi\niiiii");
	cout << endl;
	return 0;
}