
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int bit[N];

void add(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] += val;
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret += bit[i];
  return ret;
}

int func(char c) {
  if ('a' <= c && c <= 'z') return c - 'a';
  if ('A' <= c && c <= 'Z') return 26 + c - 'A';
  return 52 + c - '0';
}

char str[N];
set<int> s[70];

int main() {
  int n, q;
  scanf("%d %d %s", &n, &q, str + 1);
  for (int i = 1; i <= n; i++) {
    add(i, 1);
    int id = func(str[i]);
    s[id].insert(i);
  }
  
  while (q--) {
    int l, r;
    char c;
    scanf("%d %d %c", &l, &r, &c);
    int id = func(c);
    
    int lef = 1, rig = n;
    while (lef < rig) {
      int mid = (lef + rig) >> 1;
      if (find(mid) < l) {
        lef = mid + 1;
      } else {
        rig = mid;
      }
    }
    vector<int> rem;
    auto it = s[id].lower_bound(lef);
    while (it != s[id].end()) {
      if (find(*it) > r) break;
      rem.push_back(*it);
      it++;
    }
    for (auto it : rem) {
      s[id].erase(it);
      add(it, -1);
    }
  }
  int len = find(n);
  for (int i = 1; i <= len; i++) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (find(mid) < i) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    printf("%c", str[l]);
  }

  return 0;
}
