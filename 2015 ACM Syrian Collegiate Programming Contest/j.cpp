#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<string, int> id;
bool done[N];
vector<int> edge[N];
string a[N];

void dfs(int now) {
  if (done[now]) return;
  //cout << a[now] << endl;
  done[now] = 1;
  for (auto it : edge[now]) {
    dfs(it);
  }
}

int main() {
  ios::sync_with_stdio(0);
  
  int t;
  cin >> t;
  while (t--) {
    id.clear();
    memset(done, 0, sizeof(done));
    for (int i = 0; i < N; i++) edge[i].clear();
    
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      int c;
      cin >> a[i] >> c;
      id[a[i]] = i;
      while (c--) {
        string bef;
        cin >> bef;
        edge[i].push_back(id[bef]);
      }
    }
    while (k--) {
      string str;
      cin >> str;
      dfs(id[str]);
      //puts("HEHE");
    }
    //puts("-----");
    for (int i = 0; i < n; i++) {
      if (done[i]) printf("%s\n", a[i].c_str());
    }
  }
  
  return 0;
}
