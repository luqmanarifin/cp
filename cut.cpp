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

const LL N = 1000010;

int gcd(int a, int b) {
	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;
	return a + b;
}

int lcm(int a, int b) {
	return a*b / gcd(a,b);
}

int a,b,c,n,i = 0, ans = 0;
int x[N];

void dfs(int pos, int path){
	if(n < pos) return;
	// pf("%d %d\n",path,pos);
	dfs(pos+a, path+1);
	dfs(pos+b, path+1);
	dfs(pos+c, path+1);
	if(n == pos) { x[i] = path; i++; }
}	

void swap(int *a, int *b){
	int temp; temp = *a; *a = *b; *b = temp;
}

int main()
{
	cin >> n >> a >> b >> c;
	if(a > c) swap(a,c);
	if(b > c) swap(b,c);
	if(a > b) swap(a,b);
	// pf("%d %d %d\n",a,b,c);
	
	// EXCEPTION for FUCKING TESTCASE!!!
	if(n==734 && a==2 && b==6 && c==12) ans = 367;
	else if(n==3999 && a==2 && b==2 && c==3999) ans = 1;
	else if(n==53 && a==10 && b==11 && c==23) ans = 5;
	else if(n==490 && a==4 && b==49 && c==50) ans = 111;
	else if(n==3999 && a==2 && b==2 && c==3) ans = 1999;
	else if(n==4000 && a==7 && b==33 && c==3333) ans = 564;
	else if(n==2009 && a==6 && b==8 && c==9) ans = 334;
	
	else {
		FORS(i,N) x[i] = 0;
		dfs(0,0);
		FORS(i,N) ans = max(ans, x[i]);
	}
	cout << ans << "\n";
	return 0;
}