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
#define REP(i,a,b) for( i = a; i <= b; i++)
#define REPS(i,n) REP(i,0,n-1)
#define REPD(i,n) for( i = n-1; i >= 0; i--)

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

char a[100],b[100];
int i,n;

int main()
{
	cin >> a >> b;
	n = strlen(a);
	REPS(i,n)
		if(b[i] != a[n-i-1]){
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	return 0;
}