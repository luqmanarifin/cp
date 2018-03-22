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

long long save[N], ori[N], s[N];
int a[N];
int n, R;
long long k;

bool can(long long x) {
  long long need = 0, add = 0;
  for (int i = 1; i <= n; i++) s[i] = ori[i], save[i] = 0;
  for (int i = 1; i <= n; i++) {
    add += save[i];
    long long now = s[i] + add;
    if (now < x) {
      int at = min(n, i + R);
      int l = max(1, at - R);
      int r = min(n, at + R);
      need += x - now;
      add += x - now;
      save[r + 1] += now - x;
    }
    if (need > k) return 0;
  }
  return 1;
}

int main() {
  scanf("%d %d %lld", &n, &R, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    int l = max(1, i - R);
    int r = min(n, i + R);
    ori[l] += a[i];
    ori[r + 1] -= a[i];
  }
  for (int i = 1; i <= n; i++) ori[i] += ori[i-1];
  long long l = 0, r = 2e18;
  while (l < r) {
    long long mid = (l + r + 1) >> 1;
    if (can(mid)) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  return 0;
}
