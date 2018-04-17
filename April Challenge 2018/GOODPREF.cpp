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

const int OFFSET = 1000;
const int N = 2005;

int pre[N];
char s[N];

int find(int l, int r) {
  return pre[r] - (l? pre[l - 1] : 0);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    memset(pre, 0, sizeof(pre));

    int d;
    scanf("%s %d", s, &d);
    int n = strlen(s);
    int now = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'a') {
        now++;
      } else {
        now--;
      }
      pre[now + OFFSET]++;
    }
    for (int i = 1; i < N; i++) pre[i] += pre[i - 1];

    if (now == 0) {
      printf("%lld\n", 1LL * find(1 + OFFSET, N - 1) * d);
      continue;
    }

    int l = 1 + OFFSET, r = N - 1;
    long long ans = 0;
    for (int i = 0; i < d; i++) {
      // printf("%d %d\n", l, r);
      ans += find(l, r);
      l -= now;
      l = max(l, 0);
      l = min(l, N);
      if (l == 0) {
        ans += 1LL * find(0, N - 1) * (d - i - 1);
        break;
      }
      if (l > r) {
        break;
      }
    }
    printf("%lld\n", ans);
  }

  return 0;
}
