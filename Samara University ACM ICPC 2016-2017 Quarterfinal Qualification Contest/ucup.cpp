#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define f first
#define s second
#define mp make_pair

int n, m, r, c;

int mx, my, ax, ay;

int cost[55][55];
int tanda[55][55];

int dist[55][55][55][55];
pii bt[55][55][55][55];

char maps[55][55];

priority_queue<pip, vector<pip>, greater<pip> > pq;

inline void push(int X, int Y, int x, int y, int i, int j) {
	//if (i == 3 && j == 4) printf("%d %d %d %d\n",X, Y, x, y);
	if (X >= mx && Y >= my && X <= ax && Y <= ay && (X != r || Y != c)) {
		//if (i == 3 && j == 4) printf("masuk1\n");
		if (i >= 1 && i <= r && j == c) {
			if (X == r && Y >= 1 && Y <= c) {
				if (x == r + 1) return;
			}
		}
		if (i == r && j >= 1 && j <= c) { 
			if (X >= r && X <= n && Y == c) {
				if (y == c + 1) return;
			}
		}
		if (i >= r && i <= n && j == c) {
			if (X == r && Y >= c && Y <= m) {
				if (x == r - 1) return;
			}
		}
		if (i == r && j >= c && j <= m) {
			if (X >= 1 && X <= r && Y == c) {
				if (y == c - 1) return;
			}
		}
		if (dist[i][j][X][Y] > dist[i][j][x][y] + cost[X][Y]) {
			//if (i == 3 && j == 4) printf("masuk2\n");
			dist[i][j][X][Y] = dist[i][j][x][y] + cost[X][Y];
			bt[i][j][X][Y] = mp(x, y);
			pq.push(mp(dist[i][j][X][Y], mp(X, Y)));
		}
	}
}

inline int calc(pii A, pii B) {
	return dist[A.f][A.s][B.f][B.s];
}

inline void goback(pii tujuan, pii from) {
	int nx = from.f;
	int ny = from.s;
	int tx = tujuan.f;
	int ty = tujuan.s;
	while(tx != nx || ty != ny) {
		maps[tx][ty] = 'X';
		tujuan = bt[from.f][from.s][tx][ty];
		tx = tujuan.f;
		ty = tujuan.s;
	}
}

int tmpRES = 0;
int visited[55][55];

void flood(int x, int y) {
	if (x >= 1 && x <= n && y >= 1 && y <= m && visited[x][y] == 0) {
		visited[x][y] = 1;
		if (maps[x][y] == 'X') {
			tanda[x][y] = 1;
			tmpRES += cost[x][y];
			return;
		}
		flood(x + 1, y);
		flood(x - 1, y);
		flood(x, y + 1);
		flood(x, y - 1);
	}
}

int main() {
	scanf("%d %d %d %d",&n, &m, &r, &c);

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d",&cost[i][j]);
		}
	}
	
	
	mx = 1, my = 1, ax = n, ay = m;
	for(int i = 1; i < r; i++) {
		int j = c;
		
		for(int ii = 0; ii < 55; ii++)
			for(int jj = 0; jj < 55; jj++)
				dist[i][j][ii][jj] = 1e9,
				bt[i][j][ii][jj] = mp(0, 0);
		
		dist[i][j][i][j] = cost[i][j];
		pq.push(mp(cost[i][j], mp(i, j)));
		
		while(!pq.empty()) {
			pip top = pq.top();
			pq.pop();
			int d = top.f;
			int x = top.s.f;
			int y = top.s.s;
			
			push(x + 1, y, x, y, i, j);
			push(x - 1, y, x, y, i, j);
			push(x, y + 1, x, y, i, j);
			push(x, y - 1, x, y, i, j);
			push(x + 1, y + 1, x, y, i, j);
			push(x + 1, y - 1, x, y, i, j);
			push(x - 1, y + 1, x, y, i, j);
			push(x - 1, y - 1, x, y, i, j);
		}
	}
	
	
	// mx = 1, my = 1, ax = n, ay = c;
	for(int j = 1; j < c; j++) {
		int i = r;
		
		for(int ii = 0; ii < 55; ii++)
			for(int jj = 0; jj < 55; jj++)
				dist[i][j][ii][jj] = 1e9,
				bt[i][j][ii][jj] = mp(0, 0);
		
		dist[i][j][i][j] = cost[i][j];
		pq.push(mp(cost[i][j], mp(i, j)));
		
		while(!pq.empty()) {
			pip top = pq.top();
			pq.pop();
			int d = top.f;
			int x = top.s.f;
			int y = top.s.s;
			
			push(x + 1, y, x, y, i, j);
			push(x - 1, y, x, y, i, j);
			push(x, y + 1, x, y, i, j);
			push(x, y - 1, x, y, i, j);
			push(x + 1, y + 1, x, y, i, j);
			push(x + 1, y - 1, x, y, i, j);
			push(x - 1, y + 1, x, y, i, j);
			push(x - 1, y - 1, x, y, i, j);
		}
	}
	
	// mx = r, my = 1, ax = n, ay = m;
	for(int i = r+1; i <= n; i++) {
		int j = c;
		
		for(int ii = 0; ii < 55; ii++)
			for(int jj = 0; jj < 55; jj++)
				dist[i][j][ii][jj] = 1e9,
				bt[i][j][ii][jj] = mp(0, 0);
		
		dist[i][j][i][j] = cost[i][j];
		pq.push(mp(cost[i][j], mp(i, j)));
		
		while(!pq.empty()) {
			pip top = pq.top();
			pq.pop();
			int d = top.f;
			int x = top.s.f;
			int y = top.s.s;
			
			//if (i == 3) printf("MULAI START %d %d %d\n",x, y, d);
			
			push(x + 1, y, x, y, i, j);
			push(x - 1, y, x, y, i, j);
			push(x, y + 1, x, y, i, j);
			push(x, y - 1, x, y, i, j);
			push(x + 1, y + 1, x, y, i, j);
			push(x + 1, y - 1, x, y, i, j);
			push(x - 1, y + 1, x, y, i, j);
			push(x - 1, y - 1, x, y, i, j);
		}
	}
	
	// mx = 1, my = c, ax = n, ay = m;
	for(int j = c+1; j <= m; j++) {
		int i = r;
		
		for(int ii = 0; ii < 55; ii++)
			for(int jj = 0; jj < 55; jj++)
				dist[i][j][ii][jj] = 1e9,
				bt[i][j][ii][jj] = mp(0, 0);
		
		dist[i][j][i][j] = cost[i][j];
		pq.push(mp(cost[i][j], mp(i, j)));
		
		while(!pq.empty()) {
			pip top = pq.top();
			pq.pop();
			int d = top.f;
			int x = top.s.f;
			int y = top.s.s;
			
			push(x + 1, y, x, y, i, j);
			push(x - 1, y, x, y, i, j);
			push(x, y + 1, x, y, i, j);
			push(x, y - 1, x, y, i, j);
			push(x + 1, y + 1, x, y, i, j);
			push(x + 1, y - 1, x, y, i, j);
			push(x - 1, y + 1, x, y, i, j);
			push(x - 1, y - 1, x, y, i, j);
		}
	}
	
	pii nol, satu, dua, tiga;
	int RES = 1e9;
	
	//printf("CACAD %d\n",calc(mp(3, 4), mp(2, 5)));
	
	for(int i = 1; i < r; i++) {
		pii fi = mp(i, c);
		for(int j = 1; j < c; j++) {
			pii se = mp(r, j);
			for(int k = r + 1; k <= n; k++) {
				pii te = mp(k, c);
				for(int l = c + 1; l <= m; l++) {
					pii qu = mp(r, l);
					int Cnol = calc(fi, se) - cost[fi.f][fi.s];
					int Csatu = calc(se, te) - cost[se.f][se.s];
					int Cdua = calc(te, qu) - cost[te.f][te.s];
					int Ctiga = calc(qu, fi) - cost[qu.f][qu.s];
					int cur = Cnol + Csatu + Cdua + Ctiga;
					if (cur < RES) {
						RES = cur;
						nol = fi;
						satu = se;
						dua = te;
						tiga = qu;
					}
				}
			}
		}
	}
	4
	memset(tanda, 0, sizeof(tanda));
	memset(visited,0, sizeof(visited));
	
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++) 
			maps[i][j] = '.';
	
	goback(satu, nol);
	goback(dua, satu);
	goback(tiga, dua);
	goback(nol, tiga);
	
	flood(r, c);
	
	//printf("%d %d\n",RES, tmpRES);
	
	assert(RES == tmpRES);
	
	printf("%d\n",RES);
	
	int checkX = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++){ 
			printf("%c",maps[i][j]);
			if (maps[i][j] == 'X') checkX += cost[i][j];
		}
		printf("\n");
	}

	assert(checkX == RES);
}