#include <bits/stdc++.h>

/**
 * Competitive Programming Final CP Mahasiswa
 * Problem : F | Flow
 * Gajah Wangi (ITB)
 **/

typedef long long LL;
typedef double db;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i, a, b) for(i = a; i <= b; i++)
#define FORD(i, a, b) for(i = a; i >= b; i--)
#define FORS(i, n) for(i = 0; i < n; i++)
#define FORM(i, n) for(i = n - 1; i >= 0; i--)
#define reset(i, n) memset(i, n, sizeof(i))
#define open freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

#define pii pair<int,int>

int pet[10][10];
bool done[10][10], ada[10];
pair<pii, pii> pos[10];

bool valid(int x, int y) {
	return (1 <= x && x <= 4 && 1 <= y && y <= 4);
}

bool dfs(int x, int y, int st, int c) {
	//if(c == 2) return 1;
	
	if(pet[x][y] && pet[x][y] != c) return 0;
	if(c == 9) return 1;
	if(st) {
		pii start = pos[c].first;
		if(dfs(start.first, start.second, 0, c)) return 1;
	}
	if(mp(x, y) == pos[c].second) {
		if(dfs(0, 0, 1, c + 1)) return 1;
	}
	
	//pf("%d %d %d %d\n", x, y, st, c);
	
	if(valid(x + 1, y) && !done[x + 1][y]) {
		done[x + 1][y] = 1;
		if(dfs(x + 1, y, 0, c)) return 1;
		done[x + 1][y] = 0;
	}
	if(valid(x - 1, y) && !done[x - 1][y]) {
		done[x - 1][y] = 1;
		if(dfs(x - 1, y, 0, c)) return 1;
		done[x - 1][y] = 0;
	}
	if(valid(x, y + 1) && !done[x][y + 1]) {
		done[x][y + 1] = 1;
		if(dfs(x, y + 1, 0, c)) return 1;
		done[x][y + 1] = 0;
	}
	if(valid(x, y - 1) && !done[x][y - 1]) {
		done[x][y - 1] = 1;
		if(dfs(x, y - 1, 0, c)) return 1;
		done[x][y - 1] = 0;
	}
	return 0;
}

int main(){
	int i, j, t;
	sf("%d", &t);
	while(t--) {
		reset(done, 0);
		reset(ada, 0);
		FORS(i, 10) pos[i] = mp(mp(0, 0), mp(0, 0));
		FOR(i, 1, 4) FOR(j, 1, 4) {
			sf("%d", &pet[i][j]);
			if(pet[i][j]) {
				if(ada[pet[i][j]]) pos[pet[i][j]].second = mp(i, j);
				else pos[pet[i][j]].first = mp(i, j), ada[pet[i][j]] = 1;
			}
		}
		if(dfs(0, 0, 1, 1)) puts("SOLVABLE");
		else puts("UNSOLVABLE");
	}
	//puts("jaha");
	//#define A first
	//#define B second
	//(i, 1, 4) pf("%d %d %d %d\n", pos[i].A.A, pos[i].A.B, pos[i].B.A, pos[i].B.B);
	return 0;
}