#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int N = 1e5 + 5;

int n, k;

struct Node {
  Node() {
    dp = new int[k + 1];
    for(int i = 1; i <= k; i++) {
      dp[i] = inf;
    }
    for(int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
    cnt = 0;
  }
  ~Node() {
    delete[] dp;
    for(int i = 0; i < 26; i++) {
      if(child[i]) {
        delete child[i];
      }
    }
  }
  Node* child[26];
  int* dp;
  int cnt;
};

Node* root;
char s[N];

void dfs(Node* now) {
  for(int i = 0; i < 26; i++) {
    if(now->child[i]) {
      dfs(now->child[i]);
    }
  }
  for(int i = 0; i <= now->cnt; i++) {
    now->dp[i] = i;
  }
  for(int c = 0; c < 26; c++) {
    if(!now->child[c]) continue;
    Node* son = now->child[c];
    for(int i = k; i >= 1; i--) {
      for(int j = 1; j <= i; j++) {
        now->dp[i] = min(now->dp[i], now->dp[i - j] + son->dp[j] + 2);
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%d %d", &n, &k);
    root = new Node();
    for(int i = 0; i < n; i++) {
      scanf("%s", s);
      int len = strlen(s);
      Node* now = root;
      for(int j = 0; j < len; j++) {
        int c = s[j] - 'a';
        if(!now->child[c]) {
          now->child[c] = new Node();
        }
        now = now->child[c];
      }
      now->cnt++;
    }
    dfs(root);
    printf("Case #%d: %d\n", tt, root->dp[k]);
  }
  
  return 0;
}
