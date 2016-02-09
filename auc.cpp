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
#define REP(i,n) for( i = 0; i < n; i++)

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

int main()
{
	int i,n,maxi,max=0,seci;
	int p[1000];
	sf("%d",&n);
	REP(i,n){
		sf("%d",&p[i]);
		if(p[i] > max){
			max = p[i];
			maxi = i;
		}
	}	max = 0;
	REP(i,n)
		if((p[maxi]+p[i] > max)&&(maxi != i)){
			seci = i;
			max = p[maxi] + p[i];
		}
	pf("%d %d\n",maxi+1,p[seci]);
	return 0;
}