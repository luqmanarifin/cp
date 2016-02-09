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

int n,m,k,ans,i,a,tahu=0,tempe=0;
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for ( i=0;i<n;i++ ){
		cin >> a;
		if(a == 1) tahu+=1;
		else tempe+=1;
	}
	if(k>=tempe && m>=tahu) ans = 0;
	else if(k>=tempe && m<=tahu) ans = tahu-m;
	else ans = tempe-k-(m-tahu);
	
	if(ans<0) cout<<"0";
	else cout<<ans<<endl;
	return 0;
}