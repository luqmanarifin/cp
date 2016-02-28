#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
const int inf = 1e9;

vector<int> pos[2];
int lef[N], rig[N];
char junk[100];

int main() {
  scanf("%s", junk);
  int m, n, k;
  scanf("%d %d %d", &m, &n, &k);
  for(int i = 0; i < n; i++) {
    int at, dir;
    scanf("%d %d", &at, &dir);
    at--;
    at %= m; if(at < 0) at += m;
    pos[dir == 1].push_back(at);
  }
  int st = (pos[0].size() < pos[1].size());
  for(int j = 0; j < 2; j++) {
    if(pos[j].size()) sort(pos[j].begin(), pos[j].end());
  }
  
  for(int i = 0; i < pos[st][0]; i++) {
    lef[i] = pos[st].back();
  }
  int it = 0;
  for(int i = pos[st][0]; i < m; i++) {
    if(it < pos[st].size() && i == pos[st][it]) {
      lef[i] = i;
      it++;
    } else {
      if(i) lef[i] = lef[i - 1];
    }
  }
  
  for(int i = m - 1; i > pos[st].back(); i--) {
    rig[i] = pos[st][0];
  }
  it = (int) pos[st].size() - 1;
  for(int i = pos[st].back(); i >= 0; i--) {
    if(it >= 0 && i == pos[st][it]) {
      rig[i] = i;
      it--;
    } else {
      if(i + 1 < m) rig[i] = rig[i + 1];
    }
  }
  int predist = inf;
  for(int i = 0; i < 2; i++) {
    for(int j = 1; j < pos[i].size(); j++) {
      predist = min(predist, pos[i][j] - pos[i][j - 1]);
    }
    if(pos[i].size()) {
      predist = min(predist, pos[i][0] + m - pos[i].back());
    }
  }
  
  while(k--) {
    int t;
    scanf("%d", &t);
    int cur = predist;
    for(int it : pos[st ^ 1]) {
      it = (st ^ 1? it + 2 * t : it - 2 * t);
      it %= m; if(it < 0) it += m;
      cur = min(cur, (rig[it] + m - it >= m? rig[it] - it : rig[it] + m - it));
      cur = min(cur, (it + m - lef[it] >= m? it - lef[it] : it + m - lef[it]));
    }
    printf("%d\n", cur);
  }
  
  return 0;
}

