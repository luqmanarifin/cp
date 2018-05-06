
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 5;

int a[N];
int lef[N], rig[N];

void rem(int i) {
  //printf("remove %d\n", i);
  lef[rig[i]] = lef[i];
  rig[lef[i]] = rig[i];
}

main() {
  for (int i = 0; i < N; i++) {
    lef[i] = i - 1;
    rig[i] = i + 1;
  }
  
  int n, k, m;
  scanf("%lld %lld %lld", &n, &k, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  for (int i = n + 1; i < N; i++) a[i] = a[i - n];
  if (k > n) {
    bool allSame = 1;
    for (int i = 2; i <= n; i++) if (a[i] != a[i - 1]) allSame = 0;
    if (allSame) {
      long long all = n * m;
      long long del = all / k;
      all -= del * k;
      cout << all << endl;
    } else {
      cout << n * m << endl;
    }
    return 0;
  }
  if (m <= 2) {
    int now = 1;
    int all = m * n;
    while (now <= all) {
      int v = a[now];
      int l = now, r = now;
      set<int> s;
      s.insert(now);
      while (lef[l] >= 1 && a[lef[l]] == v) {
        l = lef[l];
        s.insert(l);
      }
      while (rig[r] <= all && a[rig[r]] == v) {
        r = rig[r];
        s.insert(r);
      }
      while (s.size() >= k) {
        for (int i = 0; i < k; i++) {
          auto it = s.begin();
          rem(*it);
          //printf("%d ", *it);
          s.erase(it);
        }
        //printf("\n");
      }
      now = rig[r];
    }
    int p = rig[0];
    int ans = 0;
    while (p <= all) {
      ans++;
      p = rig[p];
    }
    cout << ans << endl;
    return 0;
  }
  int now = 1;
  int all = 3 * n;
  long long ans = n * m;
  bool first = 1;
  while (now <= all) {
    int v = a[now];
    int l = now, r = now;
    set<int> s;
    s.insert(now);
    //printf("now %d\n", now);
    while (lef[l] >= 1 && a[lef[l]] == v) {
      l = lef[l];
      s.insert(l);
    }
    while (rig[r] <= all && a[rig[r]] == v) {
      r = rig[r];
      s.insert(r);
    }
    if (l > n) break;
    vector<int> at;
    for (auto it : s) at.push_back(it);
    if (at[0] + n <= at.back() && first) {
      first = 0;
      int kiri = 0, tengah = 0, kanan = 0;
      for (auto it : at) {
        if (it <= n) kiri++;
        else if (it > 2 * n) kanan++;
        else tengah++;
      }
      long long tot = kiri + tengah * (m - 2) + kanan;
      //printf("siklik dapet jauh %lld\n", tot);
      long long del = tot / k;
      ans -= del * k;
      if (tot == del * k) for (auto it : at) rem(it);
      
    } else if (at.back() > n && at.back() < at[0] + n) {
      int kiri = 0, tengah = 0, kanan = 0;
      for (auto it : at) {
        if (it <= n) kiri++;
        else if (it > 2 * n) kanan++;
        else tengah++;
      }
      assert(kanan == 0);
      long long tot = (kiri + tengah);
      long long del = tot / k;
      if (del && at[del * k - 1] <= n) goto JANCOK;
      //printf("kopi kiri tengah %lld\n", tot);
      
      ans -= del * k * (m - 1);
      for (int i = 0; i < del * k; i++) {
        rem(at[i]);
        rem(at[i] + n);
      }
    } else if (at.back() < at[0] + n) {
      JANCOK:;
      int kiri = 0, tengah = 0, kanan = 0;
      for (auto it : at) {
        if (it <= n) kiri++;
        else if (it > 2 * n) kanan++;
        else tengah++;
      }
      long long del = kiri / k;
      //printf("kopi kiri %lld\n", kiri);
      ans -= del * k * m;
      for (int i = 0; i < del * k; i++) {
        rem(at[i]);
        rem(at[i] + n);
        rem(at[i] + 2 * n);
      }
    } else {
      int kiri = 0, tengah = 0, kanan = 0;
      for (auto it : at) {
        if (it <= n) kiri++;
        else if (it > 2 * n) kanan++;
        else tengah++;
      }
      long long tot = (kiri + tengah + kanan);
      //printf("jujur jauh %lld\n", tot);
      long long del = tot / k;
      ans -= del * k;
      for (int i = 0; i < del * k; i++) {
        rem(at[i]);
      }
    }
    
    now = rig[r];
  }
  cout << ans << endl;
  return 0;
}
