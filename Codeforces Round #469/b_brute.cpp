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

const int N = 2e5 + 5;

int a[N];

int main() {
  for (int n = 1; n <= 10; n++) {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) a[2 * i - 1] = i;
    for (int i = 2*n - 1; i >= 1; i--) {
      if (a[i] == 0) continue;
      int at = -1;
      for (int j = i; j >= 1; j--) if (a[j] == 0) {
        at = j;
        break;
      }
      if (at == -1) break;
      a[at] = a[i];
      a[i] = 0;
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i] - 1); printf("\n");
  }

  return 0;
}
