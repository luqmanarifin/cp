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

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

char aa[30], bb[30];
int a = 0, b = 0, i;

void process (int i){
	if(aa[i]=='[' && bb[i+1]==')') a++;
	else if(aa[i]=='(' && bb[i+1]=='<') a++;
	else if(aa[i]=='8' && bb[i+1]==']') a++;
	else if(bb[i]=='[' && aa[i+1]==')') b++;
	else if(bb[i]=='(' && aa[i+1]=='<') b++;
	else if(bb[i]=='8' && aa[i+1]==']') b++;
}

int main(void)
{
	cin >> aa >> bb;
	for(i = 0; i < strlen(aa); i += 2)
		process(i);
	if(a > b) puts("TEAM 1 WINS");
	else if(a < b) puts("TEAM 2 WINS");
	else puts("TIE");
	
	return 0;
}