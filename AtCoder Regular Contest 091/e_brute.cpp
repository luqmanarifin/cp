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

int lis(vector<int>& a) {
  vector<int> d(a.size(), 1);
  int ans = 1;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        d[i] = max(d[i], d[j] + 1);
      }
    }
    ans = max(ans, d[i]);
  }
  return ans;
}

int main() {
  for (int n = 7; n <= 7; n++) {
    vector<int> a;
    for (int i = 0; i < n; i++) a.push_back(i);
    set<tuple<int, int, int>> s;
    do {
      int A = lis(a);
      reverse(a.begin(), a.end());
      int B = lis(a);
      reverse(a.begin(), a.end());
      if (!s.count(make_tuple(A + B, A, B))) {
        s.insert(make_tuple(A + B, A, B));
        for (auto it : a) printf("%d ", it); printf(": %d %d\n", A, B);
      }
    } while (next_permutation(a.begin(), a.end()));
    for (auto it : s) {
      int b, c;
      tie(ignore, b, c) = it;
      printf("%d %d\n", b, c);
    }
  }

  return 0;
}
