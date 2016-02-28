#include <bits/stdc++.h>

using namespace std;

int n_nodes;

struct Node {
public:
  Node() {
    for(int i = 0; i < 26; i++) {
      anak[i] = NULL;
    }
  }
  ~Node() {
    for(int i = 0; i < 26; i++) {
      if(anak[i]) {
        delete anak[i];
      }
    }
  }
  void add(string s) {
    Node* now = this;
    for(int i = 0; i < s.length(); i++) {
      if(!now->anak[s[i] - 'A']) {
        now->anak[s[i] - 'A'] = new Node();
        n_nodes++;
      }
      now = now->anak[s[i] - 'A'];
    }
  }
  Node* anak[26];
};

string s[10];
vector<int> occ[10];
int n, m, ans, ways;

void dfs(int i) {
  //printf("%d\n", i);
  if(i == m) {
    for(int at = 0; at < n; at++) {
      if(occ[at].empty()) {
        return;
      }
    }
    n_nodes = 0;
    for(int at = 0; at < n; at++) {
      Node* root = new Node();
      n_nodes++;
      for(auto it : occ[at]) {
        root->add(s[it]);
      }
      delete root;
    }
    if(n_nodes > ans) {
      ans = n_nodes;
      ways = 1;
    } else if(n_nodes == ans) {
      ways++;
    }
    return;
  }
  for(int at = 0; at < n; at++) {
    occ[at].push_back(i);
    dfs(i + 1);
    occ[at].pop_back();
  }
}

int main() {
  int t;
  cin >> t;
  for(int tt = 1; tt <= t; tt++) {
    cin >> m >> n;
    for(int i = 0; i < m; i++) {
      cin >> s[i];
    }
    ans = 0;
    ways = 0;
    dfs(0);
    printf("Case #%d: %d %d\n", tt, ans, ways);
    cerr << tt << " done!" << endl;
  }
  
  return 0;
}
