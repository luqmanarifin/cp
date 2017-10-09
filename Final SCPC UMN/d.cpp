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

const int N = 55;
const double eps = 1e-9;

int a[N], b[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int tt = 1; tt <= t; tt++) {
    int n, h;
    scanf("%d %d", &n, &h);
    n++;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) scanf("%d", b + i);
    bool found = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        bool ok = 1;
        double d = (double) (a[j]-a[i])/(j-i);
        for (int k = 0; k < n; k++) {
          double lim_bawah = a[i]+(k-i)*d;
          double lim_atas = lim_bawah + h;
          if (lim_bawah + eps < a[k]) ok = 0;
          if (lim_atas > b[k] + eps) ok = 0;
        }
        if (ok) found = 1;

        ok = 1;
        d = (double) (b[j]-b[i])/(j-i);
        for (int k = 0; k < n; k++) {
          double lim_atas = b[i]+(k-i)*d;
          double lim_bawah = lim_atas - h;
          if (lim_bawah + eps < a[k]) ok = 0;
          if (lim_atas > b[k] + eps) ok = 0;
        }
        if (ok) found = 1;
      }
    }
    printf("Case #%d: %s\n", tt, found? "Ya" : "Tidak");
  }
  return 0;
}
