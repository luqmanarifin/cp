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
int i,n;
int ans = 0, cok = -1;
char a[5000];
int main()
{
	cin >> a;
	n = strlen(a);
	for( i=0;i<n;++i )
		if((a[i]=='b')&&(a[i+1]=='e')&&(a[i+2]=='a')&&(a[i+3]=='r')){
			ans += (i-cok)*(n-i-3);
			cok = i;
		}
	cout << ans << endl;
	return 0;
}