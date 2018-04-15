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

void cannot(int n) {
  if (n < 6) {
    puts("-1");
    return;
  }
  vector<pair<int, int>> a = {{1, 2}, {1, 5}, {1, 6}, {2, 3}, {2, 4}};
  for (int i = 7; i <= n; i++) a.emplace_back(i, 1);
  for (auto it : a) printf("%d %d\n", it.first, it.second);
}

void can(int n) {
  for (int i = 2; i <= n; i++) printf("%d %d\n", i, i - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  cannot(n);
  can(n);
  return 0;
}
