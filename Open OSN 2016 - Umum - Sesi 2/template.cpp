#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 5;

map<string, int> mp;
string name[N];
int cnt, to[N];
vector<int> edge[N];

int get_map(string s) {
  if (!mp.count(s)) {
    name[cnt] = s;
    mp[s] = cnt++;
  }
  return mp[s];
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    vector<string> junk;
    for (int i = 0; i < 5; i++) {
      string s;
      cin >> s;
      junk.push_back(s);
    }
    int a = get_map(junk[0]);
    int b = get_map(junk[4]);
    //printf("%d %d\n", a, b);
    edge[a].push_back(b);
  }
  for (int i = 0; i < cnt; i++) {
    for (auto it : edge[i]) {
      to[it]++;
    }
  }
  priority_queue<int> q;
  for (int i = 0; i < cnt; i++) if (to[i] == 0) {
    q.push(i);
  }
  vector<int> ans;
  while (!q.empty()) {
    int now = q.top();
    //printf("%d %s\n", now, name[now].c_str());
    ans.push_back(now);
    q.pop();
    for (auto it : edge[now]) {
      to[it]--;
      if (to[it] == 0) {
        q.push(it);
      }
    }
  }
  if (ans.size() != cnt) {
    puts("Tidak Mungkin");
    return 0;
  }
  for (auto it : ans) cout << name[it] << endl;
  
  return 0;
}