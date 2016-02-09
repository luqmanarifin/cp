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
#define FORM(i,n) FORM(i, 0, n-1)
#define mp make_pair
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)
#define db double

const int N = 1000010;

int gcd(int a, int b) { if(!b) return a; return gcd(b,a%b); }
int lcm(int a, int b) { return a*b / gcd(a,b); }

struct koor{
	int X; int Y; int Z;
	int mass;
};

koor map[N];

int main(void)
{
	int n, q, i, j = -1, k; LL sum;
	sf("%d %d", &n, &q);
	int x, y, z, berat;
	int x1,y1,z1,x2,y2,z2;
	FOR(i,1,q) {
		string s; cin >> s;
		if(s[0] == 'a') {
			sf("%d %d %d %d", &x, &y, &z, &berat);
			j++;
			map[j].X = x;
			map[j].Y = y;
			map[j].Z = z;
			map[j].mass = berat;
		}
		else {
			sum = 0;
			sf("%d %d %d %d %d %d",&x1,&y1,&z1,&x2,&y2,&z2);
			FOR(k, 0, j)
				if(x1 <= map[k].X && map[k].X <= x2 && y1 <= map[k].Y && map[k].Y <= y2 && z1 <= map[k].Z && map[k].Z <= z2)
					sum += map[k].mass;
			
			pf("%lld\n", sum);
		}
	}
	
	return 0;
}
