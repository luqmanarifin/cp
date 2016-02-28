#include <iostream>
#include <cstdlib>
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
#include <utility>
#include <functional>

using namespace std;

#define LL long long
#define DB double
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

const int N = 1000010;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int n, x, up = 2*1e9, down = -up;
	sf("%d", &n);
	char sign[3], is;
	while(n--) {
		sign[1] = 'x';
		cin >> sign >> x >> is;
		if(sign[0] == '>' && sign[1] == '=') {
			if(down < x && is == 'Y')
				down = x;
			else if(up > x-1 && is == 'N')
				up = x-1;
		}
		else if(sign[0] == '>') {
			if(down < x+1 && is == 'Y') 
				down = x+1;
			else if(up > x && is == 'N')
				up = x;
		}
		else if(sign[0] == '<' && sign[1] == '=') {
			if(is == 'Y' && up > x)
				up = x;
			else if(is == 'N' && down < x+1)
				down = x+1;
		} else if(sign[0] == '<') {
			if(is == 'Y' && up > x-1)
				up = x-1;
			else if(is == 'N' && down < x)
				down = x;
		}
	}
	if(down > up) puts("Impossible");
	else cout << rand() % (up - down + 1) + down << endl;
	
	return 0;
}