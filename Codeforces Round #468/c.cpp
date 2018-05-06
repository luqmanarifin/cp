
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int s[N], cnt[N];
int bit[N];

void upd(int i, int val) {
  for (; i < N; i |= i + 1) bit[i] = max(bit[i], val);
}

int find(int i) {
  int ret = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) ret = max(ret, bit[i]);
  return ret;
}

vector<int> lis(vector<int> a) {
  memset(bit, 0, sizeof(bit));
  vector<int> ret;
  for (auto it : a) {
    int val = find(it) + 1;
    upd(it, val);
    ret.push_back(val);
  }
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    s[l]++;
    s[r + 1]--;
  }
  for (int i = 1; i <= m; i++) s[i] += s[i-1];
  vector<int> num, rnum;
  for (int i = 1; i <= m; i++) num.push_back(s[i]);
  rnum = num;
  reverse(rnum.begin(), rnum.end());
  //for (int i = 1; i <= m; i++) printf("%d ", cnt[i]); printf("\n");
  auto alis = lis(num);
  auto blis = lis(rnum);
  //for (auto it : alis) printf("%d ", it); printf("\n");
  //for (auto it : blis) printf("%d ", it); printf("\n");
  
  int ans = 0;
  for (int i = 0; i < m; i++) {
    ans = max(ans, alis[i] + blis[m - 1 - i] - 1);
  }
  cout << ans << endl;
  return 0;
}
