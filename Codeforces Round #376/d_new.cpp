#include <bits/stdc++.h>

using namespace std;

const int N = 4e6 + 5;

vector<int> w[N];
int n, c;

int in[N], out[N], all;

void insert(int l, int r) {
  in[l]++;
  out[r]++;
  in[l + c]++;
  out[r + c]++;
  all++;
}

void dfs(int l, int r, int at) {
  //printf("enter %d %d %d\n", l, r, at);
  for (int i = l; i <= r; i++) {
    if (w[i].size() <= at) {
      l = i + 1;
    } else {
      break;
    }
  }
  //puts("sip");
  for (int i = l; i <= r; i++) if (w[i].size() <= at) {
    puts("-1");
    exit(0);
  }
  //puts("good");
  if (l >= r) return;
  //puts("masuk");
  long long mini = w[l][at];
  long long maks = mini;
  //puts("acc");
  for (int i = l; i <= r; i++) {
    if (w[i][at] < maks % c) {
      maks = (maks / c + 1) * c + w[i][at];
    } else {
      maks = (maks / c) * c + w[i][at];
    }
    if (mini + c <= maks) {
      puts("-1");
      exit(0);
    }
  }
  if (mini < maks) insert(mini, maks);
  for (int i = l; i <= r; i++) {
    int j = i;
    //printf("iter %d %d %d\n", l, r, at);
    while (j + 1 <= r && w[j][at] == w[j + 1][at]) j++;
    //printf("iter %d %d %d: %d %d\n", l, r, at, i, j);
    dfs(i, j, at + 1);
    i = j;
  }
}

int main() {
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    int v;
    scanf("%d", &v);
    while (v--) {
      int a;
      scanf("%d", &a);
      w[i].push_back(--a);
    }
  }
  dfs(0, n - 1, 0);
  int now = 0;
  for (int i = 0; i < c; i++) now += out[i]++;
  for (int i = 0; i < c; i++) {
    if (now == all) {
      printf("%d\n", (c - i) % c);
      return 0;
    }
    now += out[i + c];
    now -= in[i];
  }
  puts("-1");
  return 0;
}
