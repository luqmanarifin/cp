#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int MAGIC = 225;
const int MAX_ID = 450;

long long sum[MAX_ID][MAGIC][MAGIC]; // id - modulo - entrance
long long val[MAX_ID][MAGIC][MAGIC];
int cnt[MAX_ID][MAGIC][MAGIC];

struct obj {
  long long sum;
  long long val;
  int cnt;
};

long long a[N];
int n;

long long solve(int s, int d, int k) {
  int l = s;
  int r = s + (k - 1) * d;
  int l_id = l / MAGIC;
  int r_id = r / MAGIC;
  if (d > MAGIC || r_id - l_id <= 1) {
    long long ans = 0;
    for (int i = 1; i <= k; i++) {
      ans += a[s + (i - 1) * d] * i;
    }
    return ans;
  }
  vector<obj> v;
  int lef_cnt = 0;
  long long lef_sum = 0, lef_val = 0;
  for (int i = s; i < (l_id + 1) * MAGIC; i += d) {
    s = i;
    lef_cnt++;
    lef_sum += a[i];
    lef_val += lef_cnt * a[i];
  }
  s += d;
  int cur_cnt = lef_cnt;
  v.push_back({lef_sum, lef_val, lef_cnt});
  for (int i = l_id + 1; i < r_id; i++) {
    v.push_back({sum[i][d][s % MAGIC], val[i][d][s % MAGIC], cnt[i][d][s % MAGIC]});
    cur_cnt += cnt[i][d][s % MAGIC];
    s += d * cnt[i][d][s % MAGIC];
  }
  int rig_cnt = k - cur_cnt;
  long long rig_sum = 0, rig_val = 0;
  for (int i = 0; i < rig_cnt; i++) {
    rig_sum += a[s + i * d];
    rig_val += (i + 1) * a[s + i * d];
  }
  v.push_back({rig_sum, rig_val, rig_cnt});
  long long ans = 0; cur_cnt = 0;
  for (auto it : v) {
    ans += cur_cnt * it.sum + it.val;
    cur_cnt += it.cnt;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%lld", a + i);
    int max_id = (n - 1) / MAGIC;
    for (int id = 0; id <= max_id; id++) {
      int last = min(n, (id + 1) * MAGIC);
      for (int mod = 1; mod <= MAGIC; mod++) {
        for (int e = 0; e < mod; e++) {
          cnt[id][mod][e] = 0;
          sum[id][mod][e] = 0;
          val[id][mod][e] = 0;
          for (int i = e + id * MAGIC; i < last; i += mod) {
            cnt[id][mod][e]++;
            sum[id][mod][e] += a[i];
            val[id][mod][e] += 1LL * cnt[id][mod][e] * a[i];
          }
        }
      }
    }
    for (int qq = 0; qq < q; qq++) {
      int s, d, k;
      scanf("%d %d %d", &s, &d, &k);
      s--;
      printf("%lld%c", solve(s, d, k), qq + 1 == q? '\n' : ' ');
    }
  }

  return 0;
}
