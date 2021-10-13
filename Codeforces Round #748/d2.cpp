#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 6;
const int inf = 1e9;

bool is[N];
vector<int> factors[N];
int p[N];

vector<pair<int, int>> v;
vector<int> st;

void dfs(int i, int now) {
  if (i == v.size()) {
    st.push_back(now);
    return;
  }
  for (int pw = 0; pw <= v[i].second; pw++) {
    dfs(i + 1, now);
    now *= v[i].first;
  }
}

void fill_factors(int x) {
  if (factors[x].size() > 1) return;
  int ori = x;
  v.clear();
  st.clear();
  while (x > 1) {
    if (v.empty() || v.back().first != p[x]) {
      v.emplace_back(p[x], 1);
    } else {
      int sz = v.size();
      v[sz - 1].second++;
    }
    x /= p[x];
  }
  // printf("factorizing %d\n", ori);
  // for (auto it : v) printf("%d %d\n", it.first, it.second);
  dfs(0, 1);
  sort(st.begin(), st.end());
  factors[ori] = st;
  // printf("factors %d\n", ori);
  // for (auto it : v) printf("%d %d\n", it.first, it.second);
}

int a[N];

int main() {
  for (int i = 2; i < N; i++) {
    if (p[i]) continue;
    // printf("%d ", i);
    for (int j = i; j < N; j += i) {
      if (p[j] == 0) {
        p[j] = i;
      }
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", a + i);
    }
    int ans = 0;
    for (int bi = 0; bi < n; bi++) {
      int base = a[bi];
      vector<int> num;
      for (int i = 0; i < n; i++) {
        if (a[i] >= base) {
          num.push_back(a[i] - base);
        }
      }
      // if (base == 22) {
      //   printf("num ");
      //   for (auto it : num) printf("%d ", it); printf("\n"); 
      // }
      int cnt_zero = 0;
      for (auto it : num) {
        if (it == 0) cnt_zero++;
      }
      if (cnt_zero >= n / 2) {
        ans = inf;
      }
      set<int> can_ans;
      for (auto it : num) {
        fill_factors(it);
        for (auto f : factors[it]) {
          can_ans.insert(f);
        }
      }
      // if (base == 22) {
      //   printf("can ");
      //   for (auto it : can_ans) printf("%d ", it); printf("\n"); 
      // }
      for (auto can : can_ans) {
        int agreed = 0;
        for (auto it : num) {
          if (it % can == 0) {
            agreed++;
          }
        }
        if (agreed >= n / 2) {
          ans = max(ans, can);
        }
      }
    }
    if (ans == inf) ans = -1;
    printf("%d\n", ans);
  }

  return 0;
}
