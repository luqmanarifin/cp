#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int turn = 4005;

string str[] = {"LEFT", "RIGHT", "UP", "DOWN"};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int dist(int x, int y, int xx, int yy) {
  int dx = abs(x - xx);
  int dy = abs(y - yy);
  return dx / 2 + dx % 2 + dy / 2 + dy % 2;
}

string name;
int ans = inf;

int main() {
  ios_base::sync_with_stdio(false);
  int x, y, d = -1;
  string tmp;
  cin >> x >> y;
  
  cin >> tmp;
  for(int i = 0; i < 4; i++) {
    if(tmp == str[i]) {
      d = i;
    }
  }
  int n;
  cin >> n;
  for(int it = 0; it < n; it++) {
    string s; int sx, sy;
    cin >> s >> sx >> sy;
    
    int cur = inf;
    for(int t = 0; t <= turn; t++) {
      if(dist(sx, sy, x + t*dx[d], y + t*dy[d]) <= t) {
        cur = min(cur, t);
      }
    }
    if(cur < ans) {
      ans = cur;
      name = s;
    }
  }
  cout << name << endl;
  return 0;
}
