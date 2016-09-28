#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

struct node {
  node() {
    for (int i = 0; i < 26; i++) child[i] = NULL;
    id = 0;
  }
  ~node() {
    for (int i = 0; i < 26; i++) if (child[i]) delete child[i];
  }
  int lef, rig;
  int id;
  node* child[26];
};

node* root;
int cnt, at[N];
int ans[N];

int to_rig[N], to_lef[N];

void add(char* s, int id) {
  int n = strlen(s);
  node* now = root;
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    if (now->child[c] == NULL) {
      now->child[c] = new node();
    }
    now = now->child[c];
  }
  now->id = id;
}

void dfs(node* now, int cost) {
  now->lef = cnt;
  if (now->id) {
    at[cnt++] = now->id;
  }
  for (int i = 0; i < 26; i++) {
    if (now->child[i]) {
      dfs(now->child[i], cost + 1);
    }
  }
  now->rig = cnt - 1;
  to_rig[now->lef] = min(to_rig[now->lef], cost + 1);
  to_lef[now->rig] = min(to_lef[now->rig], cost + 2);
}

char s[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    root = new node();
    cnt = 0;
    fill(to_lef, to_lef + N, inf);
    fill(to_rig, to_rig + N, inf);
    
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s);
      add(s, i);
    }
    dfs(root, 0);
    for (int i = 1; i < N; i++) {
      to_rig[i] = min(to_rig[i], to_rig[i - 1] + 1);
    }
    for (int i = N - 2; i >= 0; i--) {
      to_lef[i] = min(to_lef[i], to_lef[i + 1] + 1);
    }
    for (int i = 0; i < n; i++) {
      ans[at[i]] = min(to_lef[i], to_rig[i]);
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]); printf("\n");
    
    delete root;
  }
  
  return 0;
}
