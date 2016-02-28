#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

int a[N], b[N];
int t[N], c[N];
int ar[N], br[N];
int n, m, k, s;

bool can(int til) {
  vector<pair<long long, int>> num;
  for(int i = 0; i < m; i++) {
    if(t[i] == 1) {
      num.emplace_back(1LL * ar[til] * c[i], i);
    } else {
      num.emplace_back(1LL * br[til] * c[i], i);
    }
  }
  sort(num.begin(), num.end());
  long long need = 0;
  for(int i = 0; i < k; i++) {
    need += num[i].first;
  }
  return need <= (long long) s;
}

void solve(int til) {
  printf("%d\n", til + 1);
  int pa = -1, pb = -1;
  for(int i = 0; i <= til; i++) {
    if(a[i] == ar[til]) {
      pa = i;
    }
  }
  for(int i = 0; i <= til; i++) {
    if(b[i] == br[til]) {
      pb = i;
    }
  }
  
  vector<pair<long long, int>> num;
  for(int i = 0; i < m; i++) {
    if(t[i] == 1) {
      num.emplace_back(1LL * ar[til] * c[i], i);
    } else {
      num.emplace_back(1LL * br[til] * c[i], i);
    }
  }
  sort(num.begin(), num.end());
  for(int i = 0; i < k; i++) {
    int day = (t[num[i].second] == 1? pa : pb);
    printf("%d %d\n", num[i].second + 1, day + 1);
  }
}

int main() {
  scanf("%d %d %d %d", &n, &m, &k, &s);
  for(int i = 0; i < n; i++) {
    scanf("%d", a + i);
    ar[i] = a[i];
    if(i) ar[i] = min(ar[i], ar[i - 1]);
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", b + i);
    br[i] = b[i];
    if(i) br[i] = min(br[i], br[i - 1]);
  }
  for(int i = 0; i < m; i++) {
    scanf("%d %d", t + i, c + i);
  }
  int l = 0, r = n;
  while(l < r) {
    int mid = (l + r) >> 1;
    if(can(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if(l == n) {
    puts("-1");
  } else {
    solve(l);
  }
  return 0;
}
