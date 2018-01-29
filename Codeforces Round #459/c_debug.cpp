/*

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const long long inf = 2e18;
const int inf_int = 2e9;

#define matrix vector<vector<long long>>

matrix mul(matrix& a, matrix& b) {
  int n = a.size();
  int m = b[0].size();
  int v = a[0].size();
  matrix ret(n, vector<long long>(m, inf));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < v; k++) {
        ret[i][j] = min(ret[i][j], a[i][k] + b[k][j]);
      }
    }
  }
  return ret;
}

matrix identity(int n) {
  matrix ret(n, vector<long long>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        ret[i][j] = 0;
      } else {
        ret[i][j] = inf;
      }
    }
  }
  return ret;
}

matrix power(matrix& a, int b) {
  if (b == 0) return identity(a.size());
  matrix tmp = power(a, b / 2);
  tmp = mul(tmp, tmp);
  if (b & 1) {
    tmp = mul(tmp, a);
  }
  return tmp;
}

long long c[15];
int fir[30], sec[30];
int x, k, n, q;
map<int, int> mp;

int until(int v) {
  int ori = v;
  for (int i = 0; i < q; i++) {
    if (fir[i] <= v && v <= sec[i]) {
      v = sec[i];
    }
  }
  if (ori == v) return v;
  return until(v);
}

// -1 kalo ga ada
int zonk(int v) {
  int ret = inf_int;
  for (int i = 0; i < q; i++) {
    if (v <= fir[i]) {
      ret = min(ret, fir[i]);
    }
  }
  if (ret == inf_int) ret = -1;
  return ret;
}

// id mask
int id[1 << 8];
int mask[1 << 8];

matrix transform(matrix a, int from, int to) {
  int m = a[0].size();
  for (int i = from; i < to; i++) {
    matrix ret(1, vector<long long>(m, inf));
    for (int j = 0; j < m; j++) {
      int now = mask[j];
      if ((now & 1) == 0) {
        int to = id[now / 2];
        ret[0][to] = min(ret[0][to], a[0][j]);
      } else {
        for (int d = 1; d <= k; d++) {
          if ((now & (1 << d)) == 0) {
            int to = id[((now | (1 << d)) ^ 1) / 2];
            ret[0][to] = min(ret[0][to], a[0][j] + c[d] + mp[i + d]);
          }
        }
      }
    }
    a = ret;
  }
  return a;
}

int main() {
  scanf("%d %d %d %d", &x, &k, &n, &q);
  for (int i = 1; i <= k; i++) {
    scanf("%lld", c + i);
  }
  for (int i = 0; i < q; i++) {
    int p, w;
    scanf("%d %d", &p, &w);
    mp[p] = w;
    fir[i] = max(1, p - k);
    sec[i] = min(n - k + 1, p + 1);
    //printf("%d %d\n", fir[i], sec[i]);
  }
  //cout << mp[5] << endl;
  int pt = 0;
  memset(id, -1, sizeof(id));
  for (int i = 0; i < (1 << k); i++) {
    if (__builtin_popcount(i) != x) continue;
    mask[pt] = i;
    id[i] = pt++;
    //printf("ada %d\n", i);
  }
  //puts("mask id done");
  matrix trans(pt, vector<long long>(pt, inf));
  for (int i = 0; i < pt; i++) {
    int now = mask[i];
    if ((now & 1) == 0) {
      int to = id[now / 2];
      //printf("to %d: %d\n", to, now / 2);
      trans[i][to] = 0;
    } else {
      for (int d = 1; d <= k; d++) {
        if ((now & (1 << d)) == 0) {
          int to = id[((now | (1 << d)) ^ 1) / 2];
          //printf("to2 %d %d\n", to, ((now | (1 << d)) ^ 1) / 2);
          trans[i][to] = c[d];
        }
      }
    }
  }
  /*
  for (int i = 0; i < pt; i++) {
    for (int j = 0; j < pt; j++) {
      printf("%lld ", trans[i][j]);
    }
    printf("\n");
  }
  */
  matrix awal(1, vector<long long>(pt, inf));
  awal[0][0] = 0;
  
  //puts("done");
  
  int now = 1;
  int goal = n - k + 1;
  while (now != goal) {
    //printf("now %d\n", now);
    int til = zonk(now);
    if (til == -1) {
      //printf("ga ada zonk %d -> %d\n", now, goal);
      matrix t = power(trans, goal - now);
      awal = mul(awal, t);
      now = goal;
    } else if (til == now) {
      til = until(now);
      //printf("manual %d -> %d\n", now, til);
      awal = transform(awal, now, til);
      now = til;
    } else {
      //printf("zonk %d -> %d\n", now, til);
      matrix t = power(trans, til - now);
      awal = mul(awal, t);
      now = til;
    }    
  }
  //puts("done");
  for (int i = 0; i < pt; i++) {
    int now = mask[i];
    for (int j = 0; j < k; j++) {
      if (now & (1 << j)) {
        for (int l = j + 1; l < k; l++) {
          if ((now & (1 << l)) == 0) {
            int to = id[now ^ (1 << j) ^ (1 << l)];
            awal[0][to] = min(awal[0][to], awal[0][i] + c[l - j] + mp[goal + l]);
          }
        }
        break;
      }
    }
  }
  cout << awal[0].back() << endl;
  return 0;
}
