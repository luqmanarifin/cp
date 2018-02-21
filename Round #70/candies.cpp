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
const long long inf = 1e18;

long long a[N], b[N], n;
int k;

long long satu() {
  memset(a, 0, sizeof(a));
  if (k + k / 2 > n) return inf;
  long long sum = 0;
  for (int i = 1; i < k; i += 2) a[i] = 1, sum++;
  long long rem = n - sum;
  long long add = rem / k, pas = rem % k;
  int p = 0;
  for (int i = 1; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  for (int i = 0; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  long long mini = inf, maxi = -inf;
  for (int i = 0; i < k; i++) {
    mini = min(mini, a[i]);
    maxi = max(maxi, a[i]);
  }
  return maxi - mini;
}

long long dua() {
  memset(a, 0, sizeof(a));
  long long slot = (k % 2? k / 2 + 1 : k / 2);
  if (k + slot > n) return inf;
  long long sum = 0;
  for (int i = 0; i < k; i += 2) a[i] = 1, sum++;
  long long rem = n - sum;
  long long add = rem / k, pas = rem % k;
  int p = 0;
  for (int i = 0; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  for (int i = 1; i < k; i += 2) {
    if (p < pas) {
      a[i] += add + 1;
    } else {
      a[i] += add;
    }
    p++;
  }
  long long mini = inf, maxi = -inf;
  for (int i = 0; i < k; i++) {
    mini = min(mini, a[i]);
    maxi = max(maxi, a[i]);
  }
  return maxi - mini;
}

int main() {
  scanf("%lld %d", &n, &k);
  if (k == 1) {
    cout << n << endl;
    return 0;
  }
  if (satu() == inf && dua() == inf) {
    puts("-1");
    return 0;
  }
  if (satu() < dua()) {
    satu();
    for (int i = 0; i < k; i++) printf("%lld ", a[i]);
  } else {
    dua();
    for (int i = 0; i < k; i++) printf("%lld ", a[i]);
  }

  return 0;
}
