#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

map<string, vector<string> > edge;
map<string, int> to; 
set<string> ada;

struct item {
  item(string s) {
    this->s = s;
  }
  string s;
};

bool compare(item l, item r) {
  return l.s > r.s;
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string name;
    cin >> name;
    ada.insert(name);
    
    int ke;
    cin >> ke;
    while (ke--) {
      string buf;
      cin >> buf;
      ada.insert(buf);
      edge[buf].push_back(name);
      to[name]++;
    }
  }
  set<string>::iterator it = ada.begin();
  priority_queue<item, vector<item>, function<bool(item, item)>> pq(compare);
  while (it != ada.end()) {
    //cout << *it << endl;
    if (to[*it] == 0) {
      item temp = item(*it);
      pq.push(temp);
    }
    it++;
  }
  vector<string> ans;
  while (!pq.empty()) {
    item now = pq.top();
    pq.pop();
    ans.push_back(now.s);
    vector<string> adj = edge[now.s];
    for (int i = 0; i < adj.size(); i++) {
      to[adj[i]]--;
      if (to[adj[i]] == 0) {
        item temp = item(adj[i]);
        pq.push(temp);
      }
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i) {
      printf(" -> ");
    }
    printf("%s", ans[i].c_str());
  }
  printf("\n");
  return 0;
}
