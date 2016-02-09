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

LL n,m,a,hasil;

LL cok(LL n,LL m,LL a){
	if(n%a==0 && m%a==0) return (n/a) * (m/a);
	else if(n%a==0) return (n/a) * (m/a+1);
	else if(m%a==0) return (n/a+1) * (m/a);
	else return(n/a+1) * (m/a+1);
}
int main()
{
	sf("%I64d %I64d %I64d",&n,&m,&a);
	pf("%I64d",cok(n,m,a));
	return 0;
}