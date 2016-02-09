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

int x,y,a,b,i,start;
int ans = 0;
int main()
{
	cin>>x>>y>>a>>b;
	i = lcm(x,y);
	if(i>=a) start=i;
	else if(a%i==0) start = a;
	else start = (a/i + 1)*i;
	
	if(b%start==0) ans = (b-a)/i+1;
	else {
		while(start<=b){
			ans+=1;
			start+=i;
		}
	}
	cout<<ans<<'\n';
	return 0;
}