#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int inf = 1e9;

bool adj[N][N];
int d[N], n;

class DistanceZeroAndOne {
public:
  void add(int i, int j) {
    adj[i][j] = adj[j][i] = 1;
  }
  void del(int i, int j) {
    adj[i][j] = adj[j][i] = 0;
  }
  // O(N^2)
  int dist(int from, int to) {
    fill(d, d + N, inf);
    d[from] = 0;
    queue<int> q;
    q.push(from);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (int i = 0; i < n; i++) if (adj[now][i]) {
        if (d[now] + 1 < d[i]) {
          d[i] = d[now] + 1;
          q.push(i);
        }
      }
    }
    return d[to];
  }

  vector<string> construct(vector<int> d0, vector<int> d1) {
    memset(adj, 0, sizeof(adj));
    n = d0.size();
    vector<string> ans;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (abs(d0[i] - d0[j]) <= 1 && abs(d1[i] - d1[j]) <= 1) {
          adj[i][j] = adj[j][i] = 1;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (dist(0, i) != d0[i]) return ans;
      if (dist(1, i) != d1[i]) return ans;
    }
    for (int i = 0; i < n; i++) {
      string cur;
      for (int j = 0; j < n; j++) {
        if (adj[i][j]) {
          cur += 'Y';
        } else {
          cur += 'N';
        }
      }
      ans.push_back(cur);
    }
    return ans;
  }
};
/*
int main() {
  DistanceZeroAndOne distanceZeroAndOne;
  auto ret = distanceZeroAndOne.construct({0, 2, 1}, {1, 0, 2});
  for (auto it : ret) cout << it << endl;
  
  return 0;
}
*/