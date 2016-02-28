#include <bits/stdc++.h>

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
#define reset(i,n) memset(i, n, sizeof(i))
#define lcm(a,b) a / __gcd(a, b) * b

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

bool done[105][105][4];
char s[105][105];
int n, m;

bool is(int x, int y) {
	return s[x][y] == '^' || s[x][y] == '<' || s[x][y] == 'v' || s[x][y] == '>' || s[x][y] == '#';
}

void halangi(int x, int y, int c, int id) {
	int i, j;
	done[x][y][c] = 1;
	if(id == 0) {
		j = y;
		FORD(i, x - 1, 0) {
			if(is(i, j)) break;
			done[i][j][c] = 1;
		}
	} else if(id == 1) {
		i = x;
		FOR(j, y + 1, m - 1) {
			if(is(i, j)) break;
			done[i][j][c] = 1;
		}
	} else if(id == 2) {
		j = y;
		FOR(i, x + 1, n - 1) {
			if(is(i, j)) break;
			done[i][j][c] = 1;
		}
	} else {
		i = x;
		FORD(j, y - 1, 0) {
			if(is(i, j)) break;
			done[i][j][c] = 1;
		}
	}
}

int main(void)
{
	int t, tt;
	sf("%d", &t);
	FOR(tt, 1, t) {
		int i, j, k;
		reset(done, 0);
		sf("%d %d", &n, &m);
		FORS(i, n) sf("%s", s[i]);
		tuple<int,int,int> st (0, 0, 0);
		FORS(i, n) FORS(j, m) {
			if(s[i][j] == 'S') st = make_tuple(i, j, 0);
			else if(s[i][j] == 'G') ;
			else if(s[i][j] == '#') FORS(k, 4) done[i][j][k] = 1;
			else if(s[i][j] == '.') ;
			else {
				int id;
				char code[] = {'^', '>', 'v', '<'};
				FORS(id, 4) if(code[id] == s[i][j]) {
					FORS(k, 4) {
						//pf("%d %d %d %d\n", i, j, k, id);
						halangi(i, j, k, id);
						id = (id + 1) % 4;
					}
				}
			}
		}
		
		pf("Case #%d: ", tt);
		
		queue<tuple<int, int, int>> q;
		q.push(st);
		int x, y, c;
		tie(x, y, c) = st;
		done[x][y][c] = 1;
		
		bool reach = 0;
		while(!q.empty()) {
			tie(x, y, c) = q.front();
			//pf("%d %d %d\n", x, y, c);
			q.pop();
			if(s[x][y] == 'G') {
				pf("%d\n", c);
				reach = 1;
				break;
			}
			if(x + 1 < n) {
				if(!done[x + 1][y][(c + 1) % 4]) {
					done[x + 1][y][(c + 1) % 4] = 1;
					q.emplace(x + 1, y, c + 1);
				}
			}
			if(y + 1 < m) {
				if(!done[x][y + 1][(c + 1) % 4]) {
					done[x][y + 1][(c + 1) % 4] = 1;
					q.emplace(x, y + 1, c + 1);
				}
			}
			if(x - 1 >= 0) {
				if(!done[x - 1][y][(c + 1) % 4]) {
					done[x - 1][y][(c + 1) % 4] = 1;
					q.emplace(x - 1, y, c + 1);
				}
			}
			if(y - 1 >= 0) {
				if(!done[x][y - 1][(c + 1) % 4]) {
					done[x][y - 1][(c + 1) % 4] = 1;
					q.emplace(x, y - 1, c + 1);
				}
			}
		}
		if(!reach) puts("impossible");
		cerr << "Case " << tt << " udah!\n";
	}
	
	return 0;
}
