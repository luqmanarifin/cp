#include <bits/stdc++.h>

using namespace std;

const int N = 505;
const int inf = 2e9;

vector<int> edge[N];

string a[N];
map<string, int> mp;

bool done[N][N];

/****** Tarjan’s SCC *******/
vector< int > num, low, S, vis, st;
int cntr, numCC;

int cok[N];

int best;
vector<int> ans;

void tarjanSCC(int v) {
  low[v] = num[v] = ++cntr;
  vis[v] = 1;
  cok[v] = 1;
  S.push_back(v);
  st.push_back(v);
  for(auto u : edge[v]) {
    if(num[u] == -1) {
      tarjanSCC(u);
    } 
    if (cok[u]) {
      int cur = num[v] - num[u] + 1;
      //printf("%d ke %d cur %d\n", v, u, cur);
      if (cur < best) {
        best = cur;
        ans.clear();
        for (int i = (int) st.size() - 1; ; i--) {
          ans.push_back(st[i]);
          if (st[i] == u) break;
        }
      }
    }
    if(vis[u]) {
      low[v] = min(low[v], low[u]);
    }
  }
  if(low[v] == num[v]) {
    //printf("SCC %d :", ++numCC);
    while(1) {
      int u = S.back(); S.pop_back(); vis[u] = 0;
      //printf(" %d", u);
      if(u == v)
        break;
    }
    //printf("\n");
  }
  cok[v] = 0;
  st.pop_back();
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
  num.assign(N, -1);
  low.assign(N, 0);
  vis.assign(N, 0);
  cntr = numCC = 0;
  for(int i = 0; i < n; i++)
    if(num[i] == -1)
      tarjanSCC(i);  
  
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
