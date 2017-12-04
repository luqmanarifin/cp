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

string s = "What are you doing at the end of the world? Are you busy? Will you save us?";

string beg = "What are you doing while sending \"";
string mid = "\"? Are you busy? Will you send \"";
string last = "\"?";

const long long inf = 2e18;
const int N = 1e5 + 5;

long long len[N];

char solve(int n, long long k) {
  if (len[n] <= k) return '.';
  if (n == 0) return s[k];
  if (k < beg.size()) return beg[k];
  k -= beg.size();
  if (k < len[n - 1]) return solve(n - 1, k);
  k -= len[n - 1];
  if (k < mid.size()) return mid[k];
  k -= mid.size();
  if (k < len[n - 1]) return solve(n - 1, k);
  k -= len[n - 1];
  if (k < last.size()) return last[k];
  return '.';
}

int main() {
  len[0] = s.size();
  for (int i = 1; i < N; i++) {
    len[i] = min(inf, 2 * len[i - 1] + beg.size() + mid.size() + last.size());
    if (i <= 60) printf("%d %lld\n", i, len[i]);
  }
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    long long k;
    scanf("%d %I64d", &n, &k);
    printf("%c", solve(n, k - 1));
  }
  return 0;
}
