#include <bits/stdc++.h>

using namespace std;

const int N = 105;
const int M = 3 * N * N;

int a[N][3];

vector<int> add[3][M];
priority_queue<int> ready[3];
int last[3];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < M; j++) {
        add[i][j].clear();
      }
      while (!ready[i].empty()) ready[i].pop();
      last[i] = 0;
    }
    
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 3; j++) {
        scanf("%d", &a[i][j]);
      }
      add[0][0].push_back(i);
    }
    for (int time = 0; time < M; time++) {
      for (int i = 0; i < 3; i++) {
        for (auto it : add[i][time]) {
          if (a[it][i] == 0) {
            if (i + 1 < 3) add[i + 1][time].push_back(it);
          } else {
            ready[i].push(-it);
          }
        }
        while (last[i] <= time && !ready[i].empty()) {
          int id = -ready[i].top();
          ready[i].pop();
          int done = time + a[id][i];
          //printf("%d use %d from %d to %d\n", id + 1, i, time, done);
          if (i + 1 < 3 && done < M) add[i + 1][done].push_back(id);
          last[i] = done;
        }
      }
    }
    printf("Case #%d: %d\n", tt, max(last[0], max(last[1], last[2])));
  }

  return 0;
}
