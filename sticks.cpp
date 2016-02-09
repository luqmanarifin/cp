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

char s[302];
int n,a,b,c,i;

int main()
{
	cin >> s;
	n = strlen(s);
	FORS(i,n) if(s[i] == '+') { a = i; break; }
	FOR(i,a+1,n) if(s[i] == '=') { b = i - a - 1; break; }
	c = n - 2 - a - b;
	// pf("%d %d %d",a,b,c); nl;
	if(a + b == c) cout << s;
	else if(a + b + 2 == c)  {  cout << '|'; FOR(i,0,n-2) cout<<s[i]; }
	else if(a + b == c + 2 && a != 1) { FOR(i,1,n-1) cout<<s[i]; cout << '|'; }
	else if(a + b == c + 2) { cout << "|+"; FORS(i,b-1) cout<<'|'; cout <<'='; FORS(i,c+1) cout << '|'; }
	else cout << "Impossible";
	nl;
	return 0;
}