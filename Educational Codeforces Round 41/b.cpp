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

const int N = 1e5 + 5;

int a[N], all[N], s[N];
int ok[N];

int find(int l, int r) {
  if (l > r) return 0;
  return s[r] - s[l-1];
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    all[i] = all[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", ok + i);
    s[i] = s[i - 1];
    if (ok[i]) {
      s[i] += a[i];
    }
  }
  long long ans = 0;
  for (int i = 1; i + k - 1 <= n; i++) {
    long long cur = find(1, i - 1) + find(i + k, n) + all[i + k - 1] - all[i - 1];
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
