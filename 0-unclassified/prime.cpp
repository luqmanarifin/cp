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

const int N = 1e7;
const int N5 = N + 5;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

bool prime[N5];
int occur[N5];
LL pre[N5];

int main(void)
{
	memset(occur, 0, sizeof(occur));
	int n, i, j, temp; sf("%d", &n);
	FORS(i,n) {
		sf("%d", &temp);
		occur[temp]++;
	}
	
	memset(prime, true, sizeof(prime));
	memset(pre, 0, sizeof(pre));
	for(i = 2; i <= N; ++i) {
		pre[i] = pre[i-1];
		if(prime[i]) {
			for(j = i; j <= N; j += i) {
				prime[j] = false;
				pre[i] += occur[j];
			}
		}
	}
	
	int m, l, r; sf("%d", &m);
	FORS(i,m) {
		sf("%d %d", &l, &r);
		if(r > N) r = N;
		if(l > N) l = N;
		pf("%I64d\n", pre[r] - pre[l-1]);
	}
	
	return 0;
}