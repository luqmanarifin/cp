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
int n,m,k,i,j;
LL ans = 0;
bool a[100][100];
int main()
{
	FORS(i,100) FORS(j,100) a[i][j] = 0;
	sf("%d%d%d",&n,&m,&k);
	FORS(i,100) FOR(j,0,i) {
		if(k == 0) break;
		if(i+1-j <= n && j+1 <= m) { a[i-j][j] = 1; k--, ans += i+1; }
	}
	cout << ans << endl;
	i = 0; j = 0; 
	while(a[0][0]){
		pf("(%d,%d) ",i+1,j+1);
		if(a[i+1][j]) i++;
		else if(a[i][j+1]) j++;
		else {
			a[i][j] = 0;
			i = 0; j = 0;
			cout << endl;
		}
	}
	return 0;
}