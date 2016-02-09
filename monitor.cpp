#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <vector>
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
#define X first
#define Y second

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

pair<int,int> white[4*N];
char map[2005][2005];
pair<int,int> init, finish, pix(N, N);

int main(void)
{
	int n, m, a, b, c, d, i, j, k = 0;
	int minx, miny, maxx, maxy;
	sf("%d %d", &n, &m);
	FORS(i,n) {
		cin >> map[i];
		FORS(j,m)
			if(map[i][j] == 'w') {
				white[k] = mp(i,j);
				k++;
			}
	}
	
	FOR(a,0,n-2) {
		FOR(b,(a < white[0].X)? start:0, m-2) {
			FOR(j,1,min(n-a,m-b)-1) {
				c = a + j;
				d = b + j;
				FORS(i,k)
					if(!((white[i].X==a || white[i].X==c)&& b<=white[i].Y && white[i].Y<=d) &&
						!((white[i].Y==b || white[i].Y==d)&& a<=white[i].X && white[i].X<=c))
						goto NEXT;
				if(abs(a-c) <= pix.X && abs(b-d) <= pix.Y) {
					init = mp(a,b);
					finish = mp(c,d);
					pix.X = abs(a-c);
					pix.Y = abs(b-d);
				}	
				NEXT:;
			}
		}
	}
	
	PRINT:; nl;
	FORS(i,n)
		pf("%s\n", map[i]);
	
	return 0;
}