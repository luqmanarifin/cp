// http://www.spoj.com/problems/ALLIZWEL/
// attempt 5, feb 3 2018

#include <bits/stdc++.h>
using namespace std;

int t;

int row, col;
char grid[110][110];
bool vist[110][110];

string s = "ALLIZZWELL";
bool ada;

void dfs (int x, int y, int dist);

int main ()
{
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		ada = false;
		
		// main
		cin >> row >> col;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> grid[i][j];
			}
		}
		
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == s[0]) {
					memset(vist, false, sizeof(vist));
					dfs(i, j, 0);
					if (ada) break;
				}
			}
			if (ada) break;
		}
		
		if (ada) cout << "YES\n";
		else cout << "NO\n";
	}
	
	return 0;
}

void dfs (int r, int c, int dist)
{
	if (dist == 9) {
		ada = true;
		return;
	}
	if (vist[r][c] || ada) return;
	vist[r][c] = true;
	
	int rr[] = {0, 0, 1, 1, 1, -1, -1, -1};
	int cc[] = {1, -1, 0, 1, -1, 0, 1, -1};
	
	for (int i = 0; i < 8; i++) {
		if (r+rr[i] < 0 || r+rr[i] >= row || c+cc[i] < 0 || c+cc[i] >= col) continue;
		if (grid[r+rr[i]][c+cc[i]] == s[dist+1]) {
			dfs(r+rr[i], c+cc[i], dist+1);
			if (ada) return;
		}
	}
	
	vist[r][c] = false;
}