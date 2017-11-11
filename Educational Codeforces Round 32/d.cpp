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

long long c(int n, int k) {
  k = min(k, n - k);
  long long ans = 1;
  for (int i = 0; i < k; i++) {
    ans *= (n - i);
    ans /= i + 1;
  }
  return ans;
}

int gain[5], a[10];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  for (int len = 1; len <= 4; len++) {
    for (int i = 0; i < len; i++) a[i] = i;
    do {
      bool good = 1;
      for (int i = 0; i < len; i++) if (a[i] == i) good = 0;
      if (good) gain[len]++;
    } while (next_permutation(a, a + len));
  }
  
  long long ret = 1;
  for (int i = 2; i <= k; i++) ret += gain[i] * c(n, i);
  cout << ret << endl;
  return 0;
}
