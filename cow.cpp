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
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)

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

LL a[200000]={0};
long i,j=0,n,temp,bef,ans=0, iuh=0, iuhi=0, iuh2=0;

int main()
{
	cin>>n;
	FORS(i,n){
		cin>>temp;
		if((i==0)||(temp==bef))
			a[j]++;
		else{
			j++;
			a[j]++;
			ans += a[j-1];
			if(a[j-1]>iuh) {	
				iuh = a[j-1];
				iuhi = j-1;
			}
		}
		bef = temp;
	}
	ans += a[j];
	if(a[j]>iuh) {	
		iuh = a[j];
		iuhi = j;
	}
	FORS(i,j)
		if((a[i] > iuh2)&&(i != iuhi)) iuh2 = a[i];
	ans = ans - iuh - iuh2;
	cout << ans << "\n";
	return 0;
}