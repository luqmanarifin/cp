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
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	LL sum = 0, sesi = 5;
	int n; sf("%d", &n);
	while(sum + sesi < n) {
		sum += sesi;
		sesi*=2;
	}
	LL ans = (n - sum - 1)/(sesi/5);
	switch (ans) {
		case 0 : puts("Sheldon"); break;
		case 1 : puts("Leonard"); break;
		case 2 : puts("Penny"); break;
		case 3 : puts("Rajesh"); break;
		case 4 : puts("Howard"); break;
	}
	
	return 0;
}