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

long n,i,a,b,c,d;
int main()
{
	sf("%d",&n);
	i=n+1;
	while(i<=9013){
		a=i%10;
		b=i/10%10;
		c=i/100%10;
		d=i/1000%10;
		if(a!=b && a!= c && a!=d && b!=c && b!=d && c!=d) break;
		i+=1;
	}
	pf("%d\n",i);
	return 0;
}