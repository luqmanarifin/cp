#include <bits/stdc++.h>

/**
 * CompFest 2014 Preliminary Round - Perguruan Tinggi
 * Problem : B
 * Gajah Wangi
 */

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

bitset<64000010> done;
int n, m, kx, ky, kz;

struct pos {
	pos(int _x, int _y, int _z, int _at) : x(_x), y(_y), z(_z), at(_at) {};
	int x, y, z, at;
};

bool tepi(int a) {
	return a == 1 || a == n;
}

bool cor(int x) {
	return 1 <= x && x <= n;
}

int valid(int x, int y, int z) {
	int tep = 0;
	if(!cor(x) || !cor(y) || !cor(z)) return 0;
	if(tepi(x)) tep++;
	if(tepi(y)) tep++;
	if(tepi(z)) tep++;
	return tep;
}

int key(int x, int y, int z) {
	return (x-1)*n*n + (y-1)*n + z-1;
}

int main(void)
{
	int t, i, j, k;
	sf("%d", &t);
	while(t--) {
		done.reset();
		sf("%d %d", &n, &m);
		FORS(i, m) {
			int x, y, z;
			sf("%d %d %d", &x, &y, &z);
			done[key(x, y, z)] = 1;
		}
		int rx, ry, rz;
		sf("%d %d %d", &rx, &ry, &rz);
		sf("%d %d %d", &kx, &ky, &kz);
		
		queue<pos> q;
		q.push(pos(rx, ry, rz, 0));
		done[key(rx, ry, rz)] = 1;
		bool found = 0;
		int ans = -1;
		while(!q.empty() && !found) {
			pos now = q.front();
			q.pop();
			if(now.x == kx && now.y == ky && now.z == kz) {
				found = 1;
				ans = now.at;
			}
			if(valid(now.x+1, now.y, now.z) && !done[key(now.x+1, now.y, now.z)])
				q.push(pos(now.x+1, now.y, now.z, now.at + 1)),
				done[key(now.x+1, now.y, now.z)] = 1;
				
			if(valid(now.x-1, now.y, now.z) && !done[key(now.x-1, now.y, now.z)])
				q.push(pos(now.x-1, now.y, now.z, now.at + 1)),
				done[key(now.x-1, now.y, now.z)] = 1;
				
			if(valid(now.x, now.y+1, now.z) && !done[key(now.x, now.y+1, now.z)])
				q.push(pos(now.x, now.y+1, now.z, now.at + 1)),
				done[key(now.x, now.y+1, now.z)] = 1;
				
			if(valid(now.x, now.y-1, now.z) && !done[key(now.x, now.y-1, now.z)])
				q.push(pos(now.x, now.y-1, now.z, now.at + 1)),
				done[key(now.x, now.y-1, now.z)] = 1;
				
			if(valid(now.x, now.y, now.z+1) && !done[key(now.x, now.y, now.z+1)])
				q.push(pos(now.x, now.y, now.z+1, now.at + 1)),
				done[key(now.x, now.y, now.z+1)] = 1;
				
			if(valid(now.x, now.y, now.z-1) && !done[key(now.x, now.y, now.z-1)])
				q.push(pos(now.x, now.y, now.z-1, now.at + 1)),
				done[key(now.x, now.y, now.z-1)] = 1;
		}
		pf("%d\n", ans);
	}
	return 0;
}
