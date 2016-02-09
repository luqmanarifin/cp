#include <bits/stdc++.h>

using namespace std;

class TheKingsRoadsDiv2 {
public:
  pair<int, bool> cari_siklik (int now, int prev) {
    if(done[now]) return make_pair(0, 1);
    done[now] = 1;
    int ret = 1;
    for(auto id : edge[now]) {
      int ke = to[id];
      if(ke == prev || id == banned || id == (banned ^ 1)) continue;
      pair<int, bool> dfs = cari_siklik(ke, now);
      if(dfs.second) return make_pair(0, 1);
      ret += dfs.first;
    }
    return make_pair(ret, false);
  }
  
  string getAnswer(int h, vector <int> a, vector <int> b) {
    int sz = min(a.size(), b.size());
    int t = 0;
    for(int i = 0; i < sz; i++) {
      to.push_back(b[i]);
      edge[a[i]].push_back(t++);
      
      to.push_back(a[i]);
      edge[b[i]].push_back(t++);
    }
    for(int i = 0; i < to.size(); i += 2) {
      memset(done, 0, sizeof(done));
      banned = i;
      pair<int, bool> dfs = cari_siklik(1, -1);
      if(dfs.first == (1 << h) - 1 && !dfs.second) return "Correct";
    }
    return "Incorrect";
  }
  int banned;
  vector<int> to;
  vector<int> edge[1 << 10];
  bool done[1 << 10];
};
/*
int main() {
  TheKingsRoadsDiv2 ret;
  int h = 3;
  vector<int> a = {6, 5, 3, 3, 5, 5, 6};
  vector<int> b = {1, 5, 5, 6, 4, 7, 2};
  cout << ret.getAnswer(h, a, b) << endl;
  return 0;
}
*/