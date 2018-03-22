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

int n, T;
int a[N], t[N];

int main() {
  scanf("%d %d", &n, &T);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", t + i);
  double l = 0, r = 0, mid = 0;
  vector<pair<int, int>> vl, vr;      // power, kuota
  for (int i = 0; i < n; i++) {
    if (T < t[i]) {
      r += 1. * abs(t[i] - T) * a[i];
      vr.emplace_back(abs(t[i] - T), a[i]);
    } else if (T > t[i]) {
      l += 1. * abs(t[i] - T) * a[i];
      vl.emplace_back(abs(t[i] - T), a[i]);
    } else {
      mid += a[i];
    }
  }
  sort(vl.begin(), vl.end());
  sort(vr.begin(), vr.end());
  double totl = min(l, r), totr = min(l, r);
  double ans = mid;
  for (auto it : vl) {
    double del = min(1. * it.second, totl / it.first);
    ans += del;
    totl -= del * it.first;
  }
  for (auto it : vr) {
    double del = min(1. * it.second, totr / it.first);
    ans += del;
    totr -= del * it.first;
  }
  printf("%.15f\n", ans);
  return 0;
}
