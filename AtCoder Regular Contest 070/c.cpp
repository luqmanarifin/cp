#include <bits/stdc++.h>

using namespace std;

const int offset = 1000;
const int N = 1005;

int done[N];

int main() {
  for (int n = 1; n <= 100; n++) {
    memset(done, -1, sizeof(done));
    queue<int> q;
    done[offset] = 0;
    q.push(offset);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      if (abs(offset - now) == n) {
        cout << n << " " << done[now] << endl;
        break;
      }
      if (now+done[now]+1 < N && done[now+done[now]+1] == -1) {
        done[now+done[now]+1] = done[now]+1;
        q.push(now+done[now]+1);
      }
      if (now-done[now]-1 >= 0 && done[now-done[now]-1] == -1) {
        done[now-done[now]-1] = done[now] + 1;
        q.push(now-done[now]-1);
      }
      done[now]++;
      q.push(now);
    }
  }

  return 0;
}
