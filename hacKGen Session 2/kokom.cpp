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

const int N = 1005;
const long long inf = 2e18 + 5e16;

long long mul(long long a, long long b) {
  if (a == 0 || b == 0) return 0;
  if (inf / a < b) return inf;
  return a * b;
}

int s[N], b[N];

long long sum(long long a, long long b, long long n) {
  return mul(n, (mul(a, 2) + mul((n - 1), b))) / 2;
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d %d", s + i, b + i);
  long long l = 0, r = 5e17 + 1e10;
  while (l < r) {
    long long mid = (l + r) >> 1;
    long long ada = 0;
    for (int i = 0; i < n; i++) {
      long long lef = 0, rig = (long long) sqrt(2 * mid);
      while (lef < rig) {
        long long midd = (lef + rig + 1) >> 1;
        if (sum(s[i], b[i], midd) > mid) {
          rig = midd - 1;
        } else {
          lef = midd;
        }
      }
      // printf("%d: %lld\n", i, lef);
      ada += lef;
      if (ada >= k) break;
    }
    // cout << ada << endl;
    if (ada >= k) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << l << endl;
  return 0;
}
