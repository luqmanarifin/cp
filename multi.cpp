#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=a; i>=b; i--)
#define FORS(i,n) FOR(i,0,n-1)

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
int i,j,n,m,k,temp;

int main()
{
	sf("%d %d %d",&n,&m,&k);
	FORS(i,n) FORS(j,m) sf("%d",&temp);
	pf("%d\n",m*(m-1)/2);
	FOR(i,1,m-1) FOR(j,i+1,m)
		if(k==0)pf("%d %d\n",i,j);
		else pf("%d %d\n",j,i);
	return 0;
}