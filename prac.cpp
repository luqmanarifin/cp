#include <iostream>
#include <fstream>
#include <cstdlib>
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
#define FORS(i,n) FOR(i, 0, n-1)
#define FORD(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int n, c[100010], i, j, ans = N;

int main()
{
	open;
	sf("%d", &n);
	FORS(i,n) sf("%d", &c[i]);
	sort(c, c+n);
	j = 1;
	FORS(i,n) {
		while(2*c[i] >= c[j] && j < n-1) j++;
		if(2*c[i] < c[j])
			ans = min(ans, i+n-j);
	}
	i = n-2;
	FORD(j,n) {
		while(2*c[i] >= c[j] && i) i--;
		if(2*c[i] < c[j])
			ans = min(ans, i+n-j);
	}
	if (ans == N) ans = 0;
	cout << ans << endl;
	close;
	return 0;
}