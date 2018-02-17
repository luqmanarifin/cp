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

const int N = 37000;

vector<tuple<long long, int, int>> mp;

int main() {
  for (int i = 1; i < N; i++) {
    for (int j = 1; j <= i; j++) {
      int l = j, r = i;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (i / j <= i / mid) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      long long ans = 1LL * i * i - 1LL * (i / l) * (i / l);
      if (ans <= 1e9) {
        mp.emplace_back(ans, i, j);
      }
      j = l;
    }
    //printf("%d\n", i);
  }
  sort(mp.begin(), mp.end());
  printf("%lld %d %d\n", get<0>(mp.back()), get<1>(mp.back()), get<2>(mp.back()));
  
  /*
  for (int i = 0; i < mp.size(); i++) {
    printf("%d\n", get<0>(mp[i]));
    while (i + 1 < mp.size() && get<0>(mp[i]) == get<0>(mp[i + 1])) i++;
  }
  */
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int x;
    scanf("%d", &x);
    auto it = lower_bound(mp.begin(), mp.end(), make_tuple(x, -1, -1)) - mp.begin();
    if (it < mp.size() && get<0>(mp[it]) == x) {
      printf("%d %d\n", get<1>(mp[x]), get<2>(mp[x]));
    } else {
      puts("-1");
    }
  }
  return 0;
}
