#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N][55];

struct node {
  node() {
    for (int i = 0; i < 26; i++) {
      child[i] = NULL;
    }
    cnt = 0;
  }
  ~node() {
    for (int i = 0; i < 26; i++) {
      if (child[i]) {
        delete child[i];
      }
    }
  }
  node* child[26];
  int cnt;
};

node* root;
int ans;

void add(node* now, char* s) {
  int len = strlen(s);
  for (int i = len - 1; i >= 0; i--) {
    int c = s[i] - 'A';
    if (now->child[c] == NULL) {
      now->child[c] = new node();
    }
    now = now->child[c];
  }
  now->cnt++;
}

void dfs(node* now) {
  for (int i = 0; i < 26; i++) {
    if (now->child[i] != NULL) {
      dfs(now->child[i]);
      now->cnt += now->child[i]->cnt;
    }
  }
  if (now->cnt >= 2 && now != root) {
    now->cnt -= 2;
    ans += 2;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    root = new node();

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
      add(root, s[i]);
    }
    // puts("add done");
    ans = 0;
    dfs(root);
    printf("Case #%d: %d\n", tt, ans);

    delete root;
  } 

  return 0;
}
