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

const int N = 2005;

int a[N];
int dp[N][2], db[N][2], d[N][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i]--;
  }
  dp[0][a[0]]++;
  for (int i = 1; i < n; i++) {
    if (a[i] == 0) {
      dp[i][0] = dp[i-1][0] + 1;
      dp[i][1] = dp[i-1][1];
    } else {
      dp[i][0] = dp[i-1][0];
      dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
    }
  }
  int ans = max(dp[n-1][0], dp[n-1][1]);
  
  db[n-1][a[n-1]]++;
  for (int i = n-2; i >= 0; i--) {
    if (a[i] == 1) {
      db[i][1] = db[i+1][1] + 1;
      db[i][0] = db[i+1][0];
    } else {
      db[i][1] = db[i+1][1];
      db[i][0] = max(db[i+1][0], db[i+1][1]) + 1;
    }
  }
  
  
  for (int i = 0; i < n; i++) {
    memset(d, 0, sizeof(d));
    int zero = 0, one = 0;
    for (int j = i + 1; j + 1 < n; j++) {
      if (a[j] == 1) {
        d[j][1] = d[j-1][1] + 1;
        d[j][0] = d[j-1][0];
        one++;
      } else {
        d[j][1] = d[j-1][1];
        d[j][0] = max(d[j-1][0], d[j-1][1]) + 1;
        zero++;
      }
      ans = max(ans, dp[i][0] + zero + db[j+1][0]);
      ans = max(ans, dp[i][1] + one + db[j+1][1]);
      ans = max(ans, dp[i][0] + max(d[j][0], d[j][1]) + db[j+1][1]);
    }
  }
  cout << ans << endl;
  return 0;
}
