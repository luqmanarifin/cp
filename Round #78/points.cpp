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

multiset<int> s;

void insert(int v) {
  s.insert(v);
}

void erase(int v) {
  s.erase(s.find(v));
}

int get() {
  auto it = s.end();
  it--;
  return *it;
}

const int N = 1e5 + 5;

int a[N], d[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 1; i < n; i++) {
    d[i] = a[i] - a[i - 1];
    insert(d[i]);
  }
  int ans = get();
  for (int i = 2; i < n; i++) {
    int sum = d[i] + d[i - 1];
    erase(d[i]);
    erase(d[i - 1]);
    insert(sum / 2);
    insert(sum / 2 + sum % 2);

    ans = min(ans, get());

    insert(d[i]);
    insert(d[i - 1]);
    erase(sum / 2);
    erase(sum / 2 + sum % 2);
  }
  {
    erase(d[1]);
    int best = get();
    erase(best);
    insert(best / 2);
    insert(best / 2 + best % 2);

    ans = min(ans, get());

    insert(d[1]);
    insert(best);
    erase(best / 2);
    erase(best / 2 + best % 2);
  }
  {
    erase(d[n - 1]);
    int best = get();
    erase(best);
    insert(best / 2);
    insert(best / 2 + best % 2);

    ans = min(ans, get());

    insert(d[n - 1]);
    insert(best);
    erase(best / 2);
    erase(best / 2 + best % 2);
  }

  cout << ans << endl;
  return 0;
}
