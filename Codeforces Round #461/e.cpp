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

const long long inf = 1e18;
const int N = 1005;
const int C = 1e4 + 5;

long long dp[N][C];
long long c[N], cost[N];
set<long long> del[C];

int main() {
  int n, W, B, X;
  scanf("%d %d %d %d", &n, &W, &B, &X);
  for (int i = 0; i < n; i++) scanf("%lld", c + i);
  for (int i = 0; i < n; i++) scanf("%lld", cost + i);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < C; j++) {
      dp[i][j] = -inf;
    }
  }
  dp[0][0] = W;
  for (int i = 0; i < n; i++) {
    multiset<long long> now;
    //printf("mulai %d\n", i);
    for (int j = 0; j < C; j++) {
      //if (i == 1) printf("%d %d %lld\n", i, j, dp[i][j]);
      if (dp[i][j] >= 0) {
        int to = min(C - 1LL, min((long long) j + c[i], j + (cost[i]? dp[i][j] / cost[i] : inf)));
        long long val = dp[i][j] + j * cost[i];
        //printf("%d\n", to);
        
        now.insert(val);
        del[to].insert(val);
      }
      if (!now.empty()) {
        //printf("%d\n", now.size());
        auto it = now.end();
        it--;
        dp[i][j] = max(dp[i][j], *it - j * cost[i]);
      }
      //printf("mantap %d\n", del[j].size());
      for (auto it : del[j]) now.erase(now.find(it));
    }
    //printf("%d done\n", i);
    for (int j = 0; j < C; j++) {
      del[j].clear();
      dp[i + 1][j] = min(dp[i][j] + X, W + 1LL * j * B);
    }
  }
  for (int j = C - 1; j >= 0; j--) {
    if (dp[n][j] >= 0) {
      cout << j << endl;
      return 0;
    }
  }
  assert(0);
  return 0;
}
