#include <iostream>
#include <cstdlib>
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
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define DB double
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int a[4][2],b,c,d,e, i, j, ans = 0; LL q[10*N];
	/*	ans = 0 yg menang team 1
		ans = 1 draw
		ans = 2 team 2
		
		depan menyerang, belakang bertahan	*/
	FORS(i,4) FORS(j,2) sf("%d", &a[i][j]);
	FORS(i,4) {
		if(i%2) {
			swap(a[2][1],a[3][1]); // swap team 2
			swap(a[2][0],a[3][0]);
		} else if(i == 2) {
			swap(a[1][1],a[0][1]); // swap team 1
			swap(a[1][0],a[0][0]);
		}
		if(a[0][1] > a[3][0] && a[1][0] > a[2][1])
			ans = 0;
		else if(a[0][1] < a[3][0] && a[1][0] < a[2][1])
			ans = 2;
		else
			ans = 1;
		switch(i) {
			case 0: b = ans; break;
			case 1: c = ans; break;
			case 2: d = ans; break;
			case 3: e = ans; break;
		}
	}
	ans = min(max(b,c), max(d,e));
	
	if(ans == 2) puts("Team 2");
	else if(ans) puts("Draw");
	else puts("Team 1");
	
	return 0;
}