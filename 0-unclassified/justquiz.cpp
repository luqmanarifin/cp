#include <bits/stdc++.h>

using namespace std;

const double inf = 1e9;

double dp[105];
double con[105];

struct Trie {
  Trie() {
    cnt.clear();
    id.clear();
    edge.clear();
    child.clear();
    ans.clear();
  }
  map<string, int> id;
  vector<string> edge;
  set<string> ans;
  vector<Trie*> child;
  map<string, int> cnt;
};

Trie* root;
int n;

void add(vector<string> words, string answer) {
  Trie* now = root;
  for(auto it : words) {
    if(now->id[it] == 0) {
      now->edge.push_back(it);
      now->child.push_back(new Trie());
      now->id[it] = now->edge.size();
    }
    now->ans.insert(answer);
    now->cnt[answer]++;
    now = now->child[now->id[it] - 1];
  }
  now->ans.insert(answer);
  now->cnt[answer]++;
}

int maxh;

void get_max(Trie* now, int h) {
  maxh = max(maxh, h);
  for(auto it : now->child) {
    get_max(it, h + 1);
  }
}

void dfs(Trie* now, int h) {
  int mx = 0;
  for(auto it : now->ans) {
    mx = max(mx, now->cnt[it]);
  }
  con[h] += 1. * mx / n;
  bool ada = 0;
  for(auto it : now->child) {
    ada = 1;
    dfs(it, h + 1);
  }
  if(!ada) {
    for(int i = h + 1; i <= maxh; i++) {
      con[i] += 1. * mx / n;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int k;
  cin >> k >> n;
  cin.ignore();
  root = new Trie();
  for(int i = 0; i < n; i++) {
    string buffer;
    getline(cin, buffer);
    stringstream ss(buffer.c_str());
    vector<string> words;
    while(ss >> buffer) {
      words.push_back(buffer);
    }
    string answer = words.back();
    words.pop_back();
    add(words, answer);
  }
  get_max(root, 1);
  dfs(root, 1);
  for(int i = 0; i < 105; i++) {
    dp[i] = -inf;
  }
  dp[0] = 0;
  for(int i = 0; i <= k; i++) {
    for(int j = 1; j <= i; j++) {
      dp[i] = max(dp[i], dp[i - j] + con[j]);
    }
  }
  double ans = -inf;
  for(int i = 0; i <= k; i++) {
    ans = max(ans, dp[i]);
  }
  printf("%.15f\n", ans);
  return 0;
}
