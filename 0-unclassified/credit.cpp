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
#define open freopen("A-large-practice.in","r",stdin); freopen("A.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

int main(void)
{
	int n, m;
	open; // open file, nama file I/O tinggal ganti di #define atas
	sf("%d", &n);
	FOR(m,1,n) {
		int c, l, i, j, a[2005];
		sf("%d %d", &c, &l);
		FOR(i,1,l) sf("%d", &a[i]);
		FOR(i,1,l-1) {
			FOR(j,i+1,l) 
				if(a[i] + a[j] == c)
					goto END;
		}
		END:;
		pf("Case #%d: %d %d\n",m,i,j);		
	}
	close; // close file
	return 0;
}