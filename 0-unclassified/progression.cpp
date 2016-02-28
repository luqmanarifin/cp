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

int number[N], prog[N];
map<int,int> jarak;
vector<int> ans;

int main(void)
{
	int n, i, beda = 1;
	bool siji = 0;
	sf("%d", &n);
	FORS(i,n) 
		sf("%d", &number[i]);
	sort(number, number+n);
	FOR(i,0,n-2) {
		prog[i] = number[i+1] - number[i];
		jarak[prog[i]]++;
		if(jarak.size() == 2 && !siji) {
			beda = i;
			siji++;
		}
	}
	if(n == 1) {
		puts("-1");
		return 0; 
	}
	if(jarak.size() == 1) {
		ans.push_back(number[0] - prog[0]);
		if(!prog[0]) goto PRINT;
		if(n == 2 && prog[0]%2==0)
			ans.push_back(number[0] + prog[0]/2);
		ans.push_back(number[n-1] + prog[n-2]);
	}
	else if(jarak.size() == 2) {
		if(prog[beda]*2 == prog[beda-1] && jarak[prog[beda-1]] == 1)
			ans.push_back(number[beda] - prog[beda]);
		else if(prog[beda] == 2*prog[beda-1] && jarak[prog[beda]] == 1)
			ans.push_back(number[beda] + prog[beda-1]);
	}
	PRINT:;
	pf("%d\n", ans.size());
	if(ans.size()) {
		FORS(i,ans.size())
			pf("%d ", ans[i]);
		nl;
	}
	
	return 0;
}