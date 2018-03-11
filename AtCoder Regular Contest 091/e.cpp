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

int a[N];

int main() {
  int n, A, B;
  scanf("%d %d %d", &n, &A, &B);
  for (int i = 0; i < n; i++) a[i] = i;
  int sisa_n = n - B;
  int cluster = A - 1;
  int k = sisa_n / B + (sisa_n % B? 1 : 0);
  if (k <= cluster && cluster <= sisa_n) {
    reverse(a + n - B, a + n);
    int now = n - B;
    int makan = sisa_n - cluster;
    while (makan > 0) {
      int del = min(B - 1, makan);
      //printf("makan %d del %d\n", makan, del);
      //printf("rev %d %d\n", now - del - 1, now - 1);
      reverse(a + now - del - 1, a + now);
      makan -= del;
      now -= del + 1;
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i] + 1);
  } else {
    puts("-1");
  }

  return 0;
}
