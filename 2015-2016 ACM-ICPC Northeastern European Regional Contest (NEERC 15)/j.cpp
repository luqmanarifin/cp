#include <bits/stdc++.h>

using namespace std;

const int N = 2024;

int init[N];
int cur[N];
int n;

int ask() {
  for (int i = 0; i < n; ++i) {
    printf("%d", init[i]^cur[i]);
  }
  puts("");
  fflush(stdout);
  int res;
  scanf("%d", &res);
  if (res == n) exit(0);
  return res;
}

int main() {
  srand(time(0));
  scanf("%d", &n);
  memset(cur, 0, sizeof cur);
  for (int i = 0; i < n; ++i)
    init[i] = rand() & 1;
  vector<int> id;
  for (int i = 0; i < n; ++i)
    id.push_back(i);
  random_shuffle(id.begin(), id.end());
  bool found = 0;
  for (int i = 0; i < n; ++i) {
    cur[id[i]] ^= 1;
    int res = ask();
    if (res) {
      found = 1;
      break;
    }
  }
  assert(found);
  vector<int> sama, beda;
  random_shuffle(id.begin(), id.end());
  sama.push_back(id[0]);
  for (int i = 1; i < n; ++i) {
    cur[id[0]] ^= 1;
    cur[id[i]] ^= 1;
    int res = ask();
    if (res)
      beda.push_back(id[i]);
    else
      sama.push_back(id[i]);
    cur[id[0]] ^= 1;
    cur[id[i]] ^= 1;
    if (beda.size() == n/2) {
      for (int j = i+1; j < n; ++j)
        sama.push_back(id[j]);
      break;
    }
    if (sama.size() == n/2) {
      for (int j = i+1; j < n; ++j)
        beda.push_back(id[j]);
      break;
    }
  }
  for (int x : sama)
    cur[x] ^= 1;
  int res = ask();
  assert(res == 0);
  for (int i = 0; i < n; ++i)
    cur[i] ^= 1;
  ask();
  assert(false);
  return 0;
}