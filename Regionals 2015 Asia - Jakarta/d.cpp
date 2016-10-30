#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

vector<int> pos[5];
vector<int> ans;
int a[N], n, l, r;

bool take(int u) {
  if (pos[u + 2].size() && ans.size() + 1 <= r) {
    ans.push_back(pos[u + 2].back());
    pos[u + 2].pop_back();
    return 1;
  }
  return 0;
}

bool take_pair(int u, int v) {
  if (u == v) {
    //printf("dorama %d %d\n", pos[u + 2].size(), ans.size());
    if (pos[u + 2].size() >= 2 && ans.size() + 2 <= r) {
      take(u);
      take(v);
      return 1;
    }
  } else {
    if (pos[u + 2].size() && pos[v + 2].size() && ans.size() + 2 <= r) {
      take(u);
      take(v);
      return 1;
    }
  }
  return 0;
}

void pop() {
  if (ans.size()) {
    int val = a[ans.back()] + 2;
    pos[val].push_back(ans.back());
    ans.pop_back();
  }
}

void pop_pair() {
  pop();
  pop();
}

bool bisa_positif() {
  int negatif = pos[0].size() + pos[1].size();
  int positif = pos[3].size() + pos[4].size();
  int pair_negatif = min(negatif / 2, r / 2);
  //for (int i = 0; i < 5; i++) printf("%d ", pos[i].size()); printf("\n");
  //printf("pair %d %d %d\n", negatif, pair_negatif, positif);
  return pair_negatif * 2 + positif >= l;
}

bool bisa_nol() {
  return pos[2].size() > 0;
}

void positif() {
  while (take_pair(-2, -2));
  while (pos[4].size() > 1) {
    if (take(2) == 0) break;
  }
  //for (int i = 0; i < 5; i++) printf("%d ", pos[i].size()); printf("\n");
  for (int mask = 3; mask >= 0; mask--) {
    if ((mask & 1) && pos[4].size() == 0) continue; 
    if ((mask & 2) && (pos[0].size() == 0 || pos[1].size() == 0)) continue;
    int add = ((mask & 1)? 1 : 0) + ((mask & 2)? 2 : 0);
    if (ans.size() + add > r) continue;
    
    //printf("mask %d before %d\n", mask, ans.size());
    if (mask & 1) take(2);
    if (mask & 2) take_pair(-2, -1);
    
    //printf("sebelum %d\n", ans.size());
    
    int minus_one_pair = min((int) pos[1].size(), r - (int) ans.size()) / 2;
    //printf("minus one pair %d\n", minus_one_pair);
    for (int i = 0; i < minus_one_pair; i++) assert(take_pair(-1, -1));
    int one = min((int) pos[3].size(), r - (int) ans.size());
    for (int i = 0; i < one; i++) assert(take(1));
    //printf("lala %d %d %d size %d\n", mask, minus_one_pair, one, ans.size());
    
    if (ans.size() >= l) return;
    
    for (int i = 0; i < one; i++) pop();
    for (int i = 0; i < minus_one_pair; i++) pop_pair();
    
    if (mask & 2) pop_pair();
    if (mask & 1) pop();
  }
  assert(0);
}

void nol() {
  take(0);
  for (int i = -2; i <= 2; i++) while (take(i));
}

void negatif() {
  while (take(-1));
  while (take(1));
  while (take(-2));
  while (take(2));
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    for (int i = 0; i < 5; i++) pos[i].clear();
    ans.clear();
    
    scanf("%d %d %d", &n, &l, &r);
    for (int i = 1; i <= n; i++) {
      scanf("%d", a + i);
      pos[a[i] + 2].push_back(i);
    }
    printf("Case #%d:\n", tt);
    if (bisa_positif()) {
      positif();
    } else if (bisa_nol()) {
      nol();
    } else {
      negatif();
    }
    if (l > ans.size() || ans.size() > r) {
      puts("WA at");
      printf("%d %d %d\n", n, l, r);
      for (int i = 1; i <= n; i++) printf("%d ", a[i]);
      return 0;
    }
    assert(l <= ans.size() && ans.size() <= r);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }

  return 0;
}
