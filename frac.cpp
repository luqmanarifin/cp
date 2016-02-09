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

#define nl cout << endl
#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORM(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i,0,n-1)
#define FORD(i,n) for( i=n-1; i>=0; i--)

const LL N = 1e9+5;
const LL M = 64000;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

int t,n,i,j,k,bef = 2;
bool is[N];
int a[M],b[M],c[M];

int main()
{
	a[2] = 1; b[2] = 6;
	FOR(i,2,sqrt(N)) 
		if(!is[i]) {
			for (j = i*i; j <= N; j += i)
				is[j] = 1;
			if(i > 4) {
				a[i-1] = a[bef-1]*bef*i + (i-bef)*b[bef-1];
				b[i-1] = b[bef-1]*bef*i;
				int rem = gcd(a[i-1],b[i-1]);
				a[i-1] /= rem;
				b[i-1] /= rem;
			}
			bef = i;
		}
	FOR(i,bef+1,N) 
		if(!is[i]) {
			a[i-1] = a[bef-1]*bef*i + (i-bef)*b[bef-1];
			b[i-1] = b[bef-1]*bef*i;
			int rem = gcd(a[i-1],b[i-1]);
			a[i-1] /= rem;
			b[i-1] /= rem;
			bef = i;
		}
		
	// FOR(i,1,100) pf("%d/%d\n",a[i],b[i]);
	cin >> t;
	FORS(i,t) {
		sf("%d",&n);
		FOR(j,n+1,N) if(!is[j]) break;
		FORM(k,1,n) if(!is[k]) break;
		int p = a[j-1]*j*k - (j-1-k)*b[j-1];
		int q = b[j-1]*j*k;
		int rem = gcd(p,q);
		pf("%d/%d\n",p/rem,q/rem);
	}
	return 0;
}