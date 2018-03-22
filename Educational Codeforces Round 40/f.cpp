/*

Our shadows stretch out on the pavement
As I walk in the twilight with you
If we could be together like this forever
Holding hands
It's almost enough to make me cry

The wind grows colder
I can smell winter
Soon the season will come to this town
When I can get close to you

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just love you
I thought so with all my heart

I feel like when I'm with you
I can overcome anything
I pray that these days
Will continue forever

The wind rattled the window
The night shakes you awake
I will change any sorrow
Into a smile

The snow flowers fell
Outside the window
Unceasing
And colored our town
I realized that love means
Wanting to do something
For someone else

If I should lose you
I'll become a star and shine on you
I'll be with you even on nights
When your smile is wet with tears

This moment
When the two of us cuddle up
To gaze at the first snow flower of the year
Is overflowing with happiness

It's not dependence or weakness
I just want to be like this
With you forever
I can honestly think that now

The pure white snow flowers
Bury this town
Softly drawing memories in our hearts
Together forever with you...

*/

#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

#define matrix vector<vector<long long>>

matrix identity(int n) {
  matrix ret(n, vector<long long>(n));
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  return ret;
}

matrix mul(const matrix& a, const matrix& b) {
  int n = a.size();
  int m = b[0].size();
  matrix ret(n, vector<long long>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 0; k < a[0].size(); k++) {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= mod;
      }
    }
  }
  return ret;
}

matrix power(const matrix& a, long long b) {
  if (b == 0) return identity(a.size());
  matrix tmp = power(a, b / 2);
  tmp = mul(tmp, tmp);
  if (b & 1) {
    tmp = mul(tmp, a);
  }
  return tmp;
}

const int N = 1e5 + 5;

int sum[3][N];
vector<long long> p;
int a[N];
long long L[N], R[N];

matrix trans[10];

int id(long long u) {
  return lower_bound(p.begin(), p.end(), u) - p.begin();
}

int main() {
  int n; long long m;
  scanf("%d %lld", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d %lld %lld", a + i, L + i, R + i);
    a[i]--;
    p.push_back(L[i]);
    p.push_back(R[i] + 1);
  }
  p.push_back(2);
  p.push_back(m + 1);
  sort(p.begin(), p.end());
  p.resize(distance(p.begin(), unique(p.begin(), p.end())));
  for (int i = 0; i < n; i++) {
    int l = id(L[i]);
    int r = id(R[i] + 1);
    sum[a[i]][l]++;
    sum[a[i]][r]--;
  }
  for (int j = 0; j < 3; j++) {
    for (int i = 1; i < N; i++) {
      sum[j][i] += sum[j][i-1];
    }
  }
  trans[0] = vector<vector<long long>>(3, vector<long long>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 2 && j == 0) continue;
      if (i == 0 && j == 2) continue;
      trans[0][i][j] = 1;
    }
  }
  for (int mask = 1; mask < 8; mask++) {
    trans[mask] = trans[0];
    for (int i = 0; i < 3; i++) {
      if (mask & (1 << i)) {
        for (int j = 0; j < 3; j++) {
          trans[mask][j][i] = 0;
        }
      }
    }
  }
  vector<vector<long long>> ans(1, vector<long long>(3));
  ans[0][1] = 1;
  matrix T = identity(3);
  for (int i = 0; i + 1 < p.size(); i++) {
    long long d = p[i + 1] - p[i];
    int mask = 0;
    for (int j = 0; j < 3; j++) if (sum[j][i]) {
      mask |= (1 << j);
    }
    T = mul(T, power(trans[mask], d));
  }
  ans = mul(ans, T);
  cout << ans[0][1] << endl;
  return 0;
}
