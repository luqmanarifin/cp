#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

vector<int> edge[N];
int to[N];

int get_id(int d, int p, int c) {
  return d * 2 * 26 + p * 26 + c;
}

int main() {
  int nodes = 2 * 2 * 26;

  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    for (int d = -1; d <= 1; d++) {
      if (d == 0) continue;
      for (int st = 0; st < 4; st++) {
        for (int i = 0; i < 4; i++) {
          int at = (st + d * i + 4) % 4;
          if (s[at * 2] == '0') continue;
          int p = (s[at * 2 + 1] == '+');
          int c = (s[at * 2] - 'A');
          int d = (i & 1);
          if (i >= 2) p ^= 1;
          int id = get_id(d, p, c);
          // printf("%d %d\n", nodes, id);
          if (i == 0) {
            edge[nodes].push_back(id);
          } else if (i == 1) {
            edge[nodes].push_back(id);
          } else if (i == 2) {
            edge[id].push_back(nodes);
          } else {
            edge[id].push_back(nodes);
          }
        }
        nodes++;
      }
    }
  }
  stack<int> topo;
  for (int i = 0; i < nodes; i++) {
    for (auto it : edge[i]) {
      to[it]++;
    }
  }
  for (int i = 0; i < nodes; i++) if (to[i] == 0) {
    topo.push(i);
  }
  // puts("niki");
  int done = 0;
  while (!topo.empty()) {
    done++;
    int now = topo.top();
    topo.pop();
    for (auto it : edge[now]) {
      to[it]--;
      if (to[it] == 0) {
        topo.push(it);
      }
    }
  }
  if (done == nodes) {
    puts("bounded");
  } else {
    puts("unbounded");
  }
  return 0;
}
