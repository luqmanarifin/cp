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

const int N = 505;
const int inf = 1e9;

char s[N][N];
int dp[N], c[N];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  fill(dp, dp + N, inf);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    fill(c, c + N, inf);
    vector<int> a;
    for (int j = 0; j < m; j++) if (s[i][j] == '1') a.push_back(j);
    for (int skip = 0; skip < a.size(); skip++) {
      for (int j = 0; j <= skip; j++) {
        c[skip] = min(c[skip], a[j+a.size()-skip-1] - a[j] + 1);
      }
    }
    c[a.size()] = 0;
    //for (int j = 0; j <= a.size(); j++) printf("cost %d: %d\n", j, c[j]);
    for (int j = N - 1; j >= 0; j--) {
      dp[j] += c[0];
      for (int k = 1; k <= j; k++) {
        dp[j] = min(dp[j], dp[j-k] + c[k]);
      }
    }
  }
  int ans = inf;
  for (int i = 0; i <= k; i++) ans = min(ans, dp[i]);
  cout << ans << endl;
  return 0;
}
