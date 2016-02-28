#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<long long, bool> done;
tuple<int, int, int> temp[N];
vector<tuple<int, int, int>> seg;

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};

long long id(int x, int y) {
  return 200000LL*x + y;
}

bool ada(int x, int y) {
  int pos = lower_bound(seg.begin(), seg.end(), make_tuple(x, y + 1, 0)) - seg.begin() - 1;
  if(pos >= 0) {
    int a, b, c;
    tie(a, b, c) = seg[pos];
    if(a == x && b <= y && y <= c) {
      return 1;
    }
  }
  return 0;
}

int main() {
  int x0, y0, x1, y1;
  scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    temp[i] = make_tuple(a, b, c);
  }
  sort(temp, temp + n);
  for(int i = 0; i < n; i++) {
    int t, a, pol;
    tie(t, a, pol) = temp[i];
    for(int j = i; j < n; j++) {
      int tt, aa, bb;
      tie(tt, aa, bb) = temp[j];
      if(t == tt && aa <= pol + 1) {
        pol = max(bb, pol);
      } else {
        i = j - 1;
        break;
      }
    }
    seg.emplace_back(t, a, pol);
  }
  
  queue<tuple<int, int, int>> q;
  q.emplace(x0, y0, 0);
  done[id(x0, y0)] = 1;
  while(!q.empty()) {
    int x, y, now;
    tie(x, y, now) = q.front();
    if(x == x1 && y == y1) {
      cout << now << endl;
      return 0;
    }
    q.pop();
    for(int i = 0; i < 8; i++) {
      if(ada(x + dx[i], y + dy[i])) {
        long long index = id(x + dx[i], y + dy[i]);
        if(!done[index]) {
          done[index] = 1;
          q.emplace(x + dx[i], y + dy[i], now + 1);
        }
      }
    }
  }
  puts("-1");
  return 0;
}