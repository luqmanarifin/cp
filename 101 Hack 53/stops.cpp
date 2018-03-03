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

const int N = 5e4 + 5;
const double inf = 1e100;

double dp[N][105], a[N], sq[N], s[N];
int n, k;
map<pair<int, int>, double> mp;

double find(int l, int r) {
  double b = r - l + 1;
  double c = -2 * (s[r] - s[l-1]);
  double d = sq[r] - sq[l-1];
  double at = -c / (2 * b);
  return b * at * at + c * at + d;
}

void solve(int l, int r, int fl, int fr, int at) {
  int mid = (l + r) >> 1;
  int til = min(fr, mid - 1), p = -1;
  for (int i = fl; i <= til; i++) {
    double cur = dp[i][at-1] + find(i + 1, mid);
    if (dp[mid][at] > cur) {
      dp[mid][at] = cur;
      p = i;
    }
  }
  if (l == r) return;
  solve(l, mid, fl, p, at);
  solve(mid + 1, r, p, fr, at);
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
  sort(a + 1, a + 1 + n);
  for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i], sq[i] = sq[i-1] + a[i]*a[i];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= k; j++) {
      dp[i][j] = inf;
    }
  }
  dp[0][0] = 0;
  for (int j = 1; j <= k; j++) {
    solve(1, n, 0, n - 1, j);
    //for (int i = 1; i <= n; i++) printf("%d %d: %.3f\n", i, j, dp[i][j]);
  }
  printf("%.15f\n", dp[n][k]);
  return 0;
}
