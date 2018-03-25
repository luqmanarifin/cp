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

const int N = 5005;
const long long inf = 1e18;

long long a[N];

long long solve(int l, int r, long long h) {
  if (l == r) return 1;
  long long mini = inf;
  for (int i = l; i <= r; i++) mini = min(mini, a[i]);
  long long cur = mini - h;
  for (int i = l; i <= r; i++) {
    if (a[i] == mini) continue;
    int j = i;
    while (j + 1 <= r && a[j + 1] != mini) j++;
    cur += solve(i, j, mini);
    i = j;
  }
  return min(cur, r - l + 1LL);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", a + i);
  printf("%lld\n", solve(0, n - 1, 0));
  return 0;
}
