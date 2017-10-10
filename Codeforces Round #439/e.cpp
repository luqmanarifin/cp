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

const int N = 2505;

long long bit[N][N];

void add(int p, int q, long long v) {
  for (int i = p; i < N; i |= i + 1) {
    for (int j = q; j < N; j |= j + 1) {
      bit[i][j] += v;
    }
  }
}

long long find(int p, int q) {
  long long ret = 0;
  for (int i = p; i >= 0; i = (i & (i + 1)) - 1) {
    for (int j = q; j >= 0; j = (j & (j + 1)) - 1) {
      ret += bit[i][j];
    }
  }
  return ret;
}

long long at[N][N];

long long get_rand() {
  long long ret = 0;
  for (int i = 0; i < 4; i++) {
    ret = ret * (RAND_MAX + 1) + rand();
  }
  return ret;
}

int main() {
  srand(time(0));

  int n, m, q;
  scanf("%d %d %d", &n, &m, &q);
  while (q--) {
    int t, a, b, c, d;
    scanf("%d %d %d %d %d", &t, &a, &b, &c, &d);
    if (t == 1) {
      long long v = get_rand();
      at[a][b] = v;
      add(a, b, v);
      add(a, d + 1, -v);
      add(c + 1, b, -v);
      add(c + 1, d + 1, v);
    } else if (t == 2) {
      long long v = at[a][b];
      add(a, b, -v);
      add(a, d + 1, v);
      add(c + 1, b, v);
      add(c + 1, d + 1, -v);
    } else {
      puts(find(a, b) == find(c, d)? "Yes" : "No");
    }
  }
  return 0;
}
