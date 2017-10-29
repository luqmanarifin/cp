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

int d[N], bef[N];

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
  //for (int i = 0; i < n; i++) for (auto it : edge[i]) printf("%d %d\n", i, it);
  best = inf;
  for (int st = 0; st < n; st++) {
    fill(d, d + N, inf);
    d[st] = 0;
    queue<int> q;
    q.push(st);
    //printf("kentang source %d\n", st);
    while (!q.empty()) {
      int now = q.front();
      //printf("%d\n", now);
      q.pop();
      for (auto it : edge[now]) {
        int cur = d[now] + 1;
        if (it == st) {
          //puts("pernah siklik");
          if (best > cur) {
            best = cur;
            ans.clear();
            int p = now;
            while (1) {
              ans.push_back(p);
              if (p == st) break;
              p = bef[p];
            }
          }
        }
        if (d[it] > cur) {
          bef[it] = now;
          d[it] = cur;
          q.emplace(it);
        }
      }
    }
  }
  
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
