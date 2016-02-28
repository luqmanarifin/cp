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

char map[2005][2005];
pair<int,int> white[4*N];

int main(void)
{
	int n, m, i, j, k = 0, l;
	int minx, miny, maxx, maxy;
	sf("%d %d", &n, &m);
	FORS(i,n) {
		cin >> map[i];
		FORS(j,m) {
			if(map[i][j] == 'w') {
				if(!k) {
					minx = maxx = i;
					miny = maxy = j;
				}
				white[k] = mp(i,j); k++;
				if(i > maxx) maxx = i;
				if(j > maxy) maxy = j;
				else if(j < miny) miny = j;
			}
		}
	}
	int size = max(maxx - minx, maxy - miny) + 1;
	int dx[] = {minx, maxx - size + 1, 0};
	int dy[] = {miny, maxy - size + 1, 0};
	int a, b, c, d;
	FORS(i,3) {
		FORS(j,3) {
			a = dx[i];
			b = dy[j];
			c = dx[i] + size - 1;
			d = dy[j] + size - 1;
			if(c >= n || d >= m || a < 0 || b < 0) goto NEXT;
			FORS(l,k)
				if(!((white[l].X==a || white[l].X==c)&& b<=white[l].Y && white[l].Y<=d) &&
					!((white[l].Y==b || white[l].Y==d)&& a<=white[l].X && white[l].X<=c))
					goto NEXT;
			int p;
			FORS(p,size) {
				if(map[a][b+p] == '.')
					map[a][b+p] = '+';
				if(map[a+p][b+size-1] == '.')
					map[a+p][b+size-1] = '+';
				if(map[a+size-1-p][b] == '.')
					map[a+size-1-p][b] = '+';
				if(map[c][d-p] == '.')
					map[c][d-p] = '+';
			}

			FORS(p,n)
				pf("%s\n", map[p]);
			return 0;
			NEXT:;
		}
	}
	puts("-1");
	return 0;
}