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

const int N = 3e5 + 5;

int bit[N], done[N];

int get(int l, int r) {
  if (l > r) return 0;
  if (r < 0) return 0;
  return bit[r] - (l? bit[l - 1] : 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(done, 0, sizeof(done));
    memset(bit, 0, sizeof(bit));

    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
      int v;
      scanf("%d", &v);
      if (!done[v]) {
        done[v] = 1;
        bit[v] = 1;
      }
    }
    for (int i = 1; i < N; i++) bit[i] += bit[i-1];

    int l = 0, r = N - 1;
    while (l < r) {
      int mid = (l + r + 1) >> 1;
      int need = mid - get(0, mid - 1);
      if (need > k) {
        r = mid - 1;
      } else {
        l = mid;
      }
    }
    printf("%d\n", l);
  } 

  return 0;
}
