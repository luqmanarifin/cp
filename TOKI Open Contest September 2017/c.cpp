
#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> cache;
int nyawa = 16;
vector<int> ans;

int ask(int l, int r) {
  if (cache.count({l, r})) return cache[{l, r}];
  nyawa--;
  printf("%d", r - l + 1);
  for (int i = l; i <= r; i++) {
    printf(" %d", i);
  }
  printf("\n");
  fflush(stdout);
  int k;
  scanf("%d", &k);
  return k;
}

void dfs(int l, int r) {
  if (l == r) {
    ans.push_back(l);
    return;
  }
  int mid = (l + r) >> 1;
  int k = ask(l, mid);
  cache[{l, mid}] = k;
  cache[{mid + 1, r}] = cache[{l, r}] - k; 
  if (cache[{l, r}] == 2) {
    if (k == 0) {
      dfs(mid + 1, r);
    } else if (k == 1) {
      dfs(l, mid);
      dfs(mid + 1, r);
    } else {
      dfs(l, mid);
    }
  } else {
    if (k == 0) {
      dfs(mid + 1, r);
    } else {
      dfs(l, mid);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  cache[{1, n}] = 2;
  dfs(1, n);
  /*
  if (nyawa < 0) {
    printf("%d\n", nyawa);
    puts("MATIO COK NYAWAMU ABIS");
    assert(0);
  }
  */
  while (nyawa > 0) {
    printf("0\n");
    fflush(stdout);
    int k;
    scanf("%d", &k);
    nyawa--;
  }
  
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}
