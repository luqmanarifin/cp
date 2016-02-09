#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

struct node {
  node() {
    dp[0] = dp[1] = inf;
  }  
  node(string str) {
    now = str;
    dp[0] = dp[1] = inf;
  }
  void add(node* c) {
    mp[c->now] = child.size();
    ada.insert(c->now);
    child.push_back(c);
  }
  int st;
  int dp[2];
  string now;
  vector<node*> child;
  map<string, int> mp;
  set<string> ada;
};

node* root;

void add(vector<string> str, int stat) {
  node* now = root;
  for(int i = 0; i < str.size(); i++) {
    if(!now->ada.count(str[i])) {
      now->add(new node(str[i]));
    }
    now = now->child[now->mp[str[i]]];
  }
  now->st = stat;
}

vector<string> parse(string str) {
  vector<string> ret;
  int i = 1;
  while(i < str.length()) {
    int j = i;
    while(j < str.length() && str[j] != '/') {
      j++;
    }
    ret.push_back(str.substr(i, j - i));
    i = j + 1;
  }
  return ret;
}

void dfs(node* now) {
  if(now->child.empty()) {
    if(now->st == 1) {
      now->dp[1] = 0;
    } else {
      now->dp[0] = 0;
    }
    return;
  }
  for(auto it : now->child) {
    dfs(it);
  }
  now->dp[0] = now->dp[1] = 0;
  //printf("%s %d\n", now->now.c_str(), now->child.size());
  
  for(auto it : now->child) {
    if(now->st != 1) {
      now->dp[0] += min(it->dp[0], it->dp[1] + 1);
    }
    if(now->st != -1) {
      now->dp[1] += min(it->dp[1], it->dp[0] + 1);
    }
  }
  //printf("%s %d %d\n", now->now.c_str(), now->dp[0], now->dp[1]);
}

int main() {
  ios_base::sync_with_stdio(false);
  
  int t;
  cin >> t;
  while(t--) {
    root = new node();
    int n;
    cin >> n;
    while(n--) {
      string com, str;
      cin >> com >> str;
      int st = (com == "stage"? 1 : -1);
      vector<string> ret = parse(str);
      /*
      for(auto it : ret) {
        printf("%s\n", it.c_str());
      }
      printf("\n");
      */
      add(ret, st);
    }
    dfs(root);
    printf("%d\n", min(root->dp[0], root->dp[1] + 1));
  }
  
  return 0;
}
