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

const int N = 15;
const double eps = 1e-6;

int n, s, y;
int v[N], d[N], p[N], c[N];

double l[N], r[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d %d %d", &n, &s, &y);
    for (int i = 0; i < n; i++) scanf("%d", v + i);
    for (int i = 0; i < n; i++) scanf("%d", d + i);
    for (int i = 0; i < n; i++) scanf("%d", p + i);
    for (int i = 0; i < n; i++) scanf("%d", c + i);

    for (int i = 0; i < n; i++) {
      if (d[i] == 1) {
        p[i] = -p[i];
      } else {
        d[i] = -1;
      }
    }

    for (int i = 0; i < n; i++) {
      double dist = p[i] + c[i];
      r[i] = dist / v[i];

      l[i] = (double) p[i] / v[i];
      l[i] -= (double) y / s;

      // printf("%.15f %.15f\n", l[i], r[i]);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      if (ans + eps > l[i]) ans = max(ans, r[i]);
      ans += (double) y / s;
    }
    printf("%.15f\n", ans);
  }

  return 0;
}
