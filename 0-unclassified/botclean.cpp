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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

void print(int a, int b, int c, int d) {
	int i;
	if(a < c) FORS(i, abs(a - c)) puts("DOWN");
	else FORS(i, abs(a - c)) puts("UP");
	if(b < d) FORS(i, abs(b - d)) puts("RIGHT");
	else FORS(i, abs(b - d)) puts("LEFT");
	puts("CLEAN");
}

void next_move(int posr, int posc, vector <string> board) {
	bool done[5][5];
	int x, y;
	reset(done, 0);
	queue<pair<int,int> > q;
	q.push(mp(posr, posc));
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if(x < 0 || x > 4 || y < 0 || y > 4 || done[x][y]) continue;
		done[x][y] = 1;
		if(board[x][y] == 'd') {
			board[x][y] = 'b';
			board[posr][posc] = '-';
			print(posr, posc, x, y);
			return next_move(x, y, board);
		}
		q.push(mp(x + 1, y));
		q.push(mp(x - 1, y));
		q.push(mp(x, y + 1));
		q.push(mp(x, y - 1));
	}
}

int main(void) {
	int pos[2];
	vector <string> board;
	cin>>pos[0]>>pos[1];
	for(int i = 0; i < 5; i++) {
		string s; cin >> s;
		board.push_back(s);
	}
	next_move(pos[0], pos[1], board);
	return 0;
}
