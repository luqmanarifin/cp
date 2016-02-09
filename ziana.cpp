#include <bits/stdc++.h>

using namespace std;

const int MAGIC = 800;
const int N = 5e5 + 5;

long long add[MAGIC];
vector<pair<long long, int>> p[MAGIC];
long long a[N];
int b[N];
int blocks;

void queryone() {
  int l, r, x;
  scanf("%d %d %d", &l, &r, &x);
  l--; r--;
  for(int i = b[l] + 1; i < b[r]; i++) {
    add[i] += x;
  }
  for(auto& it : p[b[l]]) {
    if(l <= it.second && it.second <= r) {
      it.first += x;
    }
  }
  if(b[l] != b[r]) {
    for(auto& it : p[b[r]]) {
      if(l <= it.second && it.second <= r) {
        it.first += x;
      }
    }
  }
  sort(p[b[l]].begin(), p[b[l]].end());
  sort(p[b[r]].begin(), p[b[r]].end());
}

void querytwo() {
  long long y;
  scanf("%I64d", &y);
  int l = -1, r = -2;
  for(int i = 0; i < blocks; i++) {
    y -= add[i];
    int id = lower_bound(p[i].begin(), p[i].end(), make_pair(y, -1)) - p[i].begin();
    if(id < p[i].size() && p[i][id].first == y) {
      if(l == -1) {
        l = p[i][id].second;
      }
      id = lower_bound(p[i].begin(), p[i].end(), make_pair(y, N)) - p[i].begin();
      r = p[i][id - 1].second;
    }
    y += add[i];
  }
  printf("%d\n", r - l);
}

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for(int i = 0; i < n; i++) {
    scanf("%I64d", a + i);
  }
  int sz = sqrt(n);
  for(int i = 0; i * sz < n; i++) {
    blocks++;
    for(int j = i * sz; j < n && j < (i + 1) * sz; j++) {
      p[i].emplace_back(a[j], j);
      b[j] = i;
    }
    sort(p[i].begin(), p[i].end());
  }
  while(q--) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      queryone();
    } else {
      querytwo();
    }
  }
  
  return 0;
}
