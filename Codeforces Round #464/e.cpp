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

const int N = 5e5 + 5;

long long a[N], s[N];
int sz;

double get(int num) {
  long long tot = a[sz - 1] + (num > 1? s[num - 2] : 0);
  return (double) tot / num;
}

int main() {
  int q;
  scanf("%d", &q);
  double ans = 0;
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x;
      scanf("%d", &x);
      a[sz] = x;
      s[sz] = (sz? s[sz - 1] : 0) + x;
      sz++;
      
      int l = 1, r = sz;
      while (r - l > 3) {
        int lf = l + (r - l) / 3;
        int rf = r - (r - l) / 3;
        if (get(lf) > get(rf)) {
          l = lf;
        } else {
          r = rf;
        }
      }
      for (int i = l; i <= r; i++) {
        //printf("get %d: %.15f\n", i, get(i));
        ans = max(ans, x - get(i));
      }
    } else {
      printf("%.15f\n", ans);
    }
  }
  return 0;
}
