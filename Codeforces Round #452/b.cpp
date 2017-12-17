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

vector<int> f = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<int> s;

int main() {
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < f.size(); j++) {
      s.push_back(f[j] + (i == 5 && j == 1));
    }
  }
  //for (auto it : s) printf("%d ", it); printf("\n");
  int n;
  scanf("%d", &n);
  vector<int> a;
  while (n--) {
    int v;
    scanf("%d", &v);
    a.push_back(v);
  }
  //for (auto it : a) printf("%d ", it); printf("\n");
  for (int i = 0; i + a.size() <= s.size(); i++) {
    bool ok = 1;
    for (int j = 0; j < a.size(); j++) {
      if (a[j] != s[i + j]) {
        //printf("%d %d\n", i, i + j);
        ok = 0;
        break;
      }
    }
    if (ok) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
