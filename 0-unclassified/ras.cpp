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

int n,c,i,x[100];
int ans = 0;
int main()
{
	sf("%d %d",&n,&c);
	for(i = 0; i<n ; ++i){
		sf("%d",&x[i]);
		if((i > 0) && (x[i-1]-x[i]-c > ans)) ans = x[i-1]-x[i]-c;
	}
	pf("%d",ans);
	return 0;
}