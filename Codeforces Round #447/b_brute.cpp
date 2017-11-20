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

int ans[15][1 << 10][2];

int main() {
  for (int n = 1; n <= 7; n++) {
    for (int m = 1; m <= 7; m++) {
      memset(ans, 0, sizeof(ans));
      ans[0][0][0] = ans[0][0][1] = 1;
      for (int i = 1; i <= n; i++) {
        for (int k = 0; k < (1 << m); k++) {
          for (int j = 0; j < (1 << m); j++) {
            if (__builtin_popcount(j) % 2) {
              ans[i][k][1] += ans[i-1][k ^ j][1];
            } else {
              ans[i][k][0] += ans[i-1][k ^ j][0];
            }
          }
        }
      }
      printf("%d %d: %d %d\n", n, m, ans[n][(1 << m) - 1][1], ans[n][0][0]);
    }
  }

  return 0;
}
