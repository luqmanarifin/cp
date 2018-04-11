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

const int N = 20;

int a[N];

bool sq(int n) {
  int q = (int) sqrt(n);
  if (q * q == n) return 1;
  q++;
  if (q * q == n) return 0;
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  int len = 0;
  for (int i = 0; n; i++) {
    len++;
    a[i] = n % 10;
    n /= 10;
  }
  int ans = N;
  for (int mask = 0; mask < (1 << len); mask++) {
    if (__builtin_popcount(mask) == len) continue;
    bool can = 1;
    for (int i = len - 1; i >= 0; i--) {
      if ((mask & (1 << i)) == 0) {
        if (a[i] == 0) {
          can = 0;
        }
        break;
      }
    }    
    if (!can) continue;
    int now = 0;
    for (int i = len - 1; i >= 0; i--) {
      if ((mask & (1 << i)) == 0) {
        now = now * 10 + a[i];
      }
    }
    if (sq(now)) {
      //cout << now << endl;
      ans = min(ans, __builtin_popcount(mask));
    }
  }
  if (ans == N) {
    puts("-1");
  } else {
    cout << ans << endl;
  }
  return 0;
}
