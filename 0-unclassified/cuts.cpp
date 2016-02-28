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
#define FORM(i,a,b) for( i=b; i>=a; i--)
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
int a,b,c,i,n,arr[8010];
int main()
{
	cin >> n >> a >> b >> c;
	FOR(i,1,8000) arr[i] = 0;
	arr[a] = 1; arr[b] = 1; arr[c] = 1;
	FOR(i,1,n)
		if(arr[i] > 0){
			if(arr[i] + 1 > arr[i+a]) arr[i+a] = arr[i] + 1;
			if(arr[i] + 1 > arr[i+b]) arr[i+b] = arr[i] + 1;
			if(arr[i] + 1 > arr[i+c]) arr[i+c] = arr[i] + 1;
		}
	cout << arr[n] << endl;
}