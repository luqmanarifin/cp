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

int n,i;
int main()
{
	cin>>n;
	if(n%2==1) cout<<"-1";
	else{
		for( i=1;i<=n;++i ){
			if(i%2==0)cout<<i-1<<" ";
			else cout<<i+1<<" ";
		}
	}

	return 0;
}