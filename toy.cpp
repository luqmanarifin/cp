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
#define FORM(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;
const int maxnum = 1e6;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int sim(int a) {
	return maxnum + 1 - a;
}

bool que[N], ans[N], used[N];
int res = 0;

int main(void)
{
	int n, i;
	sf("%d", &n);
	
	memset(used, 0, sizeof(used));
	memset(ans, 0, sizeof(ans));
	while(n--) {
		int temp; sf("%d", &temp);
		que[temp]++;
		used[temp]++;
	}
	int j = 1;
	FOR(i,1,maxnum)
		if(que[i] && !que[sim(i)]) {
			ans[sim(i)]++;
			res++;
		}
		else if(que[i] && que[sim(i)] && i <= maxnum/2) {
			while(used[j] || used[sim(j)]) j++;
			ans[j]++; ans[sim(j)]++;
			used[j]++; used[sim(j)]++;
			res += 2;
		}
	
	pf("%d\n", res);
	FOR(i,1,maxnum) if(ans[i]) pf("%d ", i);
	nl;
	
	return 0;
}