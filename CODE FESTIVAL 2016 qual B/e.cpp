#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct node {
  node() {
    for (int i = 0; i < 26; i++) child[i] = 0;
    id = 0;
    cnt = 0;
  }
  node* child[26];
  int id, cnt;
};

char s[4 * N], per[30];
int cnt[N][26][26], up[N];
node* root;

void add(char* s, int id) {
  int n = strlen(s);
  node* now = root;
  for (int i = 0; i < n; i++) {
    int c = s[i] - 'a';
    if (now->child[c] == NULL) {
      now->child[c] = new node();
    }
    now->cnt++;
    now = now->child[c];
  }
  now->cnt++;
  now->id = id;
}

void dfs(node* now, int z[26][26], int carry) {
  if (now->id) {
    up[now->id] = carry;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        cnt[now->id][i][j] = z[i][j];
      }
    }
    carry++;
  }
  int lower[26] = {};
  for (int i = 0; i < 26; i++) {
    if (now->child[i] == NULL) continue;
    lower[i] = now->child[i]->cnt;
  }
  for (int i = 0; i < 26; i++) {
    if (now->child[i] == NULL) continue;
    for (int j = 0; j < 26; j++) {
      if (i == j) continue;
      z[i][j] += lower[j];
    }
    dfs(now->child[i], z, carry);
    for (int j = 0; j < 26; j++) {
      if (i == j) continue;
      z[i][j] -= lower[j];
    }
  }
}

int tmp[26][26];

int main() {
  int n;
  scanf("%d", &n);
  root = new node();
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    add(s, i);
  }
  dfs(root, tmp, 0);
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    scanf("%d %s", &k, per);
    int bef = up[k] + 1;
    for (int i = 0; i < 26; i++) {
      for (int j = i + 1; j < 26; j++) {
        bef += cnt[k][per[j]-'a'][per[i]-'a'];
      }
    }
    printf("%d\n", bef);
  }
  
  return 0;
}
