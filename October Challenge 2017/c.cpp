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
const long long mod = (1LL << 32);

int n;

int main() {
  string s, buf;
  while (getline(cin, s)) {
    stringstream ss(s);
    vector<long long> a;
    while (ss >> buf) {
      a.push_back(atoi(buf.c_str()));
    }
    n = a.size();

    long long tot = 0;
    for (int i = 0; i < n; i++) tot += a[i];
    cerr << n << ' ' << tot << ' ' << tot % mod << endl;
    assert((tot + a[1]) % mod == 0);

    long long best = 1e18, p = -1;
    long long nbest = 1e18, np = -1;
    for (int i = 0; i < n; i++) {
      long long cur = (tot + a[i]);
      long long ncur = (tot + a[i]) % mod;
      if (cur < best) {
        best = cur;
        p = i;
      }
      if (ncur < nbest) {
        nbest = ncur;
        np = i;
      }
    }
    if (p == np) {
      printf("kenapa sama? padahal %lld %lld\n", best, nbest);
    }
  }

  return 0;
}
