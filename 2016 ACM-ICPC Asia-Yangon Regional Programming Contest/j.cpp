#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int inf = 1e9;

pair<int, int> bit[N];
vector<int> all;
int back[N];

pair<int, int> find(int i) {
  pair<int, int> ret = {-inf, -inf};
  for (; i >= 0; i = (i & (i + 1)) - 1) {
    ret = max(ret, bit[i]);
  }
  return ret;
}

void update(int i, pair<int, int> val) {
  for (; i < N; i |= i + 1) {
    bit[i] = max(bit[i], val);
  }
}

int id(int val) {
  return lower_bound(all.begin(), all.end(), val) - all.begin();
}

vector<int> lis(vector<int> a, int s) {
  memset(back, -1, sizeof(back));
  all.clear();
  for (auto it : a) all.push_back(it);
  all.push_back(s);
  sort(all.begin(), all.end());
  all.resize(distance(all.begin(), unique(all.begin(), all.end())));
  s = id(s);
  for (int i = 0; i < a.size(); i++) a[i] = id(a[i]);
  
  vector<int> ret;
  ret.assign(a.size(), 0);
  int st = 0;
  while (st < a.size() && a[st] != s) st++;
  for (int i = 0; i < N; i++) bit[i] = {-inf, -inf};
  update(a[st], {1, st});
  printf("JANCOK %d\n", s);
  for (int i = st + 1; i < a.size(); i++) {
    pair<int, int> bef = find(a[i] - 1);
    printf("%d %d %d\n", i, bef.first, bef.second);
    back[i] = bef.second;
    update(a[i], {bef.first + 1, i});
  }
  int now = find(N - 1).second;
  for (int i = 0; i < a.size(); i++) printf("%d ", back[i]); printf("\n");
  while (now >= 0) {
    ret[now] = 1;
    now = back[now];
  }
  return ret;
}

long long can(vector<int> a, int st) {
  vector<int> en = lis(a, st);
  vector<int> num;
  int num_lis = 0;
  for (int i = 0; i < a.size(); i++) {
    if (en[i] == 0) {
      num.push_back(a[i] + 1);
    } else {
      num_lis++;
    }
  }
  sort(num.begin(), num.end());
  long long ret = a.size() - num_lis;
  int last = (num.size()? num[0] : 0);
  for (int i = 1; i < num.size(); i++) {
    long long be = max(last + 1, num[i]);
    ret += be - num[i];
    last = be;
  }
  if (num.size() && last >= st) {
    return -1;
  } else {
    return ret;
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n;
    scanf("%d", &n);
    vector<int> a;
    vector<int> num;
    int maks = 0;
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      maks = max(maks, v);
      a.push_back(v);
      num.push_back(v);
    }
    num.push_back(maks + 1);
    sort(num.begin(), num.end());
    num.resize(distance(num.begin(), unique(num.begin(), num.end())));
    int l = 0, r = num.size() - 1;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (can(a, num[mid]) == -1) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    printf("Case %d: %I64d\n", tt, can(a, num[l]));
  }
  return 0;
}
