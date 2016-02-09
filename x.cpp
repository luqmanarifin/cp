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

char a[310];

int main()
{
	int n, i, j;
	char one, two;
	sf("%d", &n);
	sf("%s", &a);
	one = a[0]; two = a[1];
	if(one == two) { puts("NO"); return 0; }
	FORS(i,n) {
		if(i) sf("%s", &a);
		FORS(j,n)
			if(j == i || j == n-i-1) {
				if(a[j] != one) {
					puts("NO");
					return 0;
				}
			} else if(a[j] != two) {
				puts("NO");
				return 0;
			}
	}
	puts("YES");
	return 0;
}