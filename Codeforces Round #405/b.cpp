#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 5;

int k;
vector<int> edge[N];

struct item {
  item() {
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
  }
  void add(item other) {
    for (int i = 0; i < k; i++) {
      this->a[i] += other.a[i];
      this->cnt[i] += other.cnt[i];
    }
  }
  void rotate() {
    long long tmp = a[k - 1];
    for (int i = k - 1; i > 0; i--) a[i] = a[i - 1];
    a[0] = tmp;
    
    int tm = cnt[k - 1];
    for (int i = k - 1; i > 0; i--) cnt[i] = cnt[i - 1];
    cnt[0] = tm;
  }
  long long a[5];
  int cnt[5];
};

item p[N];
long long ans;

void dfs(int now, int bef) {
  long long ret = 0, tot = 0;
  for (auto it : edge[now]) if (it != bef) {
    //printf("edge %I64d\n", it);
    dfs(it, now);
    p[it].rotate();
    p[it].cnt[0]++;
    p[it].a[0] += p[it].cnt[0];
    //for (int i = 0; i < k; i++) printf("la %I64d %I64d\n", p[it].cnt[i], p[it].a[i]);
    
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        int dist = i + j + 2;
        int jump = (dist + k - 1) / k;
        tot += p[now].cnt[i] * p[it].a[j] + p[now].a[i] * p[it].cnt[j];
        if (jump == 1) {
          tot -= p[now].cnt[i] * p[it].cnt[j];
        }
      }
    }
    
    p[now].add(p[it]);
  }
  //printf("%I64d anak anak %I64d\n", now, tot);
  for (int i = 0; i < k; i++) {
    //printf("%I64d %I64d %I64d\n", i, p[now].cnt[i], p[now].a[i]);
    tot += p[now].a[i];
  }
  ans += tot;
  //printf("%I64d nyumbang %I64d\n", now, tot);
}

main() {
  int n;
  scanf("%I64d %I64d", &n, &k);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%I64d %I64d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}
