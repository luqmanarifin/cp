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

const int N = 1100;

int gcd(int a, int b) { return b? gcd(b,a%b): a; }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int n, i, j, k;
	int number[N][N], point[N], now[N];
	bool eksis[N][N];
	sf("%d", &n);
	FORS(i,n) {
		sf("%d", &point[i]);
		FORS(j,point[i]) {
			sf("%d", &number[i][j]);
			eksis[i][number[i][j]]++;
		}
	}
	FORS(i,n) {
		memcpy(now, point, sizeof(point));
		FORS(j,point[i]) {
			FORS(k,n) {
				if(eksis[k][number[i][j]])
					now[k]--;
			}	
		}
		bool menang = 1;
		FORS(j,n)
			if(!now[j] && i != j) {
				menang = 0;
				break;
			}
		puts(menang? "YES": "NO");
	}
	
	return 0;
}