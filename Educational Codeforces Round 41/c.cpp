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

const int N = 105;

char s[5][N][N];
int c[5][2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%s", s[i][j]);
    }
  }
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        int asli = (j + k) % 2;
        if (s[i][j][k] - '0' != asli) {
          c[i][0]++;
        } else {
          c[i][1]++;
        }
      } 
    }
  }
  int ans = 1e9;
  for (int mask = 0; mask < (1 << 4); mask++) {
    if (__builtin_popcount(mask) != 2) continue;
    int cur = 0;
    for (int i = 0; i < 4; i++) {
      if (mask & (1 << i)) {
        cur += c[i][1];
      } else {
        cur += c[i][0];
      }
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
