#include <iostream>
#include <fstream>
#include <cstdlib>
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
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define PI acos(-1.0)
#define sf scanf
#define pf printf
#define nl printf("\n")
#define FOR(i,a,b) for( i=a; i<=b; i++)
#define FORD(i,a,b) for( i=b; i>=a; i--)
#define FORS(i,n) FOR(i, 0, n-1)
#define FORM(i,n) FORD(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int n,k,l,r,s,sk,rem,i ;

int main()
{
	sf("%d %d %d %d %d %d",&n,&k,&l,&r,&s,&sk);
	int a[n];
	rem = sk % k;
	FORS(i,k){
		a[i] = sk/k;
		if(rem > 0) { a[i]++; rem--; }
	}

	if(n != k){
		rem = (s - sk)%(n-k);
		FOR(i,k,n-1){
			a[i] = (s-sk)/(n-k);
			if(rem > 0) { a[i]++; rem--; }
		}
	}
	random_shuffle(a,a+n);
	FORS(i,n) pf("%d ",a[i]); nl;
	return 0;
}