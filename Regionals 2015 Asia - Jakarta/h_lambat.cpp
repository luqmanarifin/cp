#include <bits/stdc++.h>

using namespace std;

const int N = 605;
const int BIG = 1e6 + 5;
const long long inf = 1e18;

int p[N], q[N];
vector<int> pos, a;
int id[BIG];

long long b[N];
int med[N];

long long dp[N];
int clef[BIG], slef[BIG], crig[BIG], srig[BIG], A, B;

long long find(int l, int r, int center) {
  assert(l <= r);
  if (l <= center && center <= r) {
    return slef[center] - slef[l] - 1LL * clef[l - 1] * (center - l)
         + srig[center] - srig[r] - 1LL * crig[r + 1] * (r - center);
  } else if (center < l) {
    long long mid = srig[l] - srig[r] - 1LL * crig[r + 1] * (r - l);
    long long cnt_mid = crig[l] - crig[r + 1];
    return mid + 1LL * cnt_mid * (l - center);
  } else {
    long long mid = slef[r] - slef[l] - 1LL * clef[l - 1] * (r - l);
    long long cnt_mid = clef[r] - clef[l - 1];
    return mid + 1LL * cnt_mid * (center - r);
  }
  assert(0);
}

// cari vector of median, yang tetap adalah mesin di machine
void find_median(int machine, int til) {
  for (int i = 0; i < pos.size(); i++) {
    if (i <= til) {
      b[i] = 1LL * (clef[pos[i]] - (pos[i]? clef[pos[i] - 1] : 0)) * B;
    } else {
      b[i] = 0;
    }
  }
  b[pos.size()] = 0;
  long long now = 0;
  int pt_med = 0;
  for (int i = til - 1; i >= 0 && machine < pos[i] && A >= now + b[i]; i--) {
    med[pt_med++] = machine;
    now += b[i];
  }
  
  long long all = A;
  for (int i = 0; i < pt_med; i++) all += b[til - 1 - i];
  if (til <= id[machine]) {
    b[til] = A;
  } else {
    b[til] = 0;
  }
  int j = til;
  now = b[j];
  for (int i = til - pt_med - 1; i >= 0; i--) {
    all += b[i];
    while (now * 2 < all && j) {
      if (j - 1 == id[machine]) now += A;
      now += b[j - 1];
      j--;
    }
    med[pt_med++] = (pos[j]? pos[j] : machine);
  }
  reverse(med, med + pt_med);
}

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    pos.clear();
    a.clear();
    fill(dp, dp + N, inf);
    memset(clef, 0, sizeof(clef));
    memset(slef, 0, sizeof(slef));
    memset(crig, 0, sizeof(crig));
    memset(srig, 0, sizeof(srig));
    
    int n, m;
    scanf("%d %d %d %d", &n, &m, &A, &B);
    
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      v++;
      a.push_back(v);
      pos.push_back(v);
    }
    long long ans = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d %d", p + i, q + i);
      p[i]++;
      clef[p[i]]++;
      crig[p[i]]++;
      ans += 1LL * q[i] * B;
      pos.push_back(p[i]);
    }
    pos.push_back(0);
    pos.push_back(BIG - 1);
    sort(pos.begin(), pos.end());
    pos.resize(distance(pos.begin(), unique(pos.begin(), pos.end())));
    for (int i = 0; i < pos.size(); i++) id[pos[i]] = i;
    sort(a.begin(), a.end());
    
    //puts("beby");
    for (int i = 1; i < BIG; i++) {
      clef[i] += clef[i - 1];
      slef[i] = slef[i - 1] + clef[i - 1];
    }
    for (int i = BIG - 2; i >= 0; i--) {
      crig[i] += crig[i + 1];
      srig[i] = srig[i + 1] + crig[i + 1];
    }
    //puts("DP done");
    
    dp[0] = 0;
    for (int it = 0; it < a.size(); it++) {
      int now = id[a[it]];
      int bef = 1;
      int aft = pos.size() - 2;
      //printf("lala %d %d %d\n", bef, now, aft);
      for (int j = aft; j >= bef; j--) {
        find_median(a[it], j + 1);
        //printf("%d %d: ", a[it], j);
        //for (auto it : med) printf("%d ", it); printf("\n");
        for (int i = j; i >= bef; i--) {
          long long add = 1LL * abs(a[it] - med[i]) * A + find(pos[i], pos[j], med[i]) * B;
          dp[j] = min(dp[j], dp[i - 1] + add);
        }
      }
    }
    printf("Case #%d: %lld\n", tt, ans + dp[pos.size() - 2]);
  }
 
  return 0;
}
