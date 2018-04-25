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

const int N = 30;

int banned[10];
long long n;
long long dp[N][3];
int a[N];

int dig(long long i) {
  if (i < 10) return 1;
  return 1 + dig(i / 10);
}

int main() {
  for (int i = 0; i < 10; i++) scanf("%d", banned + i);
  scanf("%lld", &n);
  n--;
  long long ans = !banned[0];
  if (n == 0) {
    cout << ans << endl;
    return 0;
  }
  int len = dig(n);
  long long tmp = n;
  for (int i = len; i >= 1; i--) {
    a[i] = tmp % 10;
    tmp /= 10;
  }
  for (int i = 1; i < 10; i++) {
    if (banned[i]) continue;
    if (i < a[1]) {
      dp[1][0]++;
    } else if (i == a[1]) {
      dp[1][1]++;
    } else {
      dp[1][2]++;
    }
  }
  for (int j = 1; j < len; j++) {
    for (int i = 0; i < 10; i++) {
      if (banned[i]) continue;
      dp[j + 1][0] += dp[j][0];

      if (i < a[j + 1]) {
        dp[j + 1][0] += dp[j][1];
      } else if (i == a[j + 1]) {
        dp[j + 1][1] += dp[j][1];
      } else {
        dp[j + 1][2] += dp[j][1];
      }

      dp[j + 1][2] += dp[j][2];
    }
  }
  for (int j = 1; j < len; j++) {
    //printf("len %d: %lld %lld %lld\n", j, dp[j][0], dp[j][1], dp[j][2]);
    ans += dp[j][0] + dp[j][1] + dp[j][2];
  }
  ans += dp[len][0] + dp[len][1];
  cout << ans << endl;
  return 0;
}
