#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int inf = 2e9;

vector<int> edge[N];

string a[N];
map<string, int> mp;

bool done[N][N];

int best;
vector<int> ans;

bool vis[N], st[N];
vector<int> S;
int num[N];

void dfs(int now) {
  vis[now] = 1;
  st[now] = 1;
  num[now] = S.size();
  S.push_back(now);
  for (auto it : edge[now]) {
    if (st[it]) {
      int cur = num[now] - num[it] + 1;
      if (cur < best) {
        best = cur;
        ans.clear();
        for (int i = S.size() - 1; ; i--) {
          ans.push_back(S[i]);
          if (S[i] == it) break;
        }
      }
    }
    if (!vis[it]) dfs(it);
  }
  S.pop_back();
  st[now] = 0;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i], mp[a[i]] = i;
  for (int i = 0; i < n; i++) {
    string s;
    int k;
    cin >> s >> k;
    assert(s == a[i]);
    cin.ignore();
    while (k--) {
      string buf, x;
      getline(cin, buf);
      vector<string> num;
      stringstream ss(buf);
      while (ss >> x) {
        num.push_back(x);
      }
      for (int j = 1; j + 1 < num.size(); j++) {
        num[j] = num[j].substr(0, num[j].size() - 1);
      }
      for (int j = 1; j < num.size(); j++) {
        int to = mp[num[j]];
        if (done[i][to]) continue;
        done[i][to] = 1;
        edge[i].push_back(to);
      }
    }
  }
  best = inf;
// In MAIN();
  for(int i = 0; i < n; i++)
    if(vis[i] == 0)
      dfs(i);  
  
  //cout << best << endl;
  if (best == inf) {
    puts("SHIP IT");
  } else {
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
      printf("%s%c", a[ans[i]].c_str(), " \n"[i == n - 1]);
    }
  }
  
  return 0;
}
