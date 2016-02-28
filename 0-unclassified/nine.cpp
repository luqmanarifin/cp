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

int n=0,i=0,e=0,t=0,ans;
char s[100],len,a;

int main()
{
	sf("%s", &s); 
	len = strlen(s);
	FORS(a,len){
		if(s[a] == 'n') n++;
		else if(s[a] == 'i') i++;
		else if(s[a] == 't') t++;
		else if(s[a] == 'e') e++;
	}
	ans = min((n-1)/2,min(i,min(e/3,t)));
	// pf("%d %d %d %d\n",n,i,t,e);
	cout << ans << endl;
	return 0;
}