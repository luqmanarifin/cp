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

const long long mod = 998244353;
const int N = 5005;

long long fact[N], ifact[N];

long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long tmp = power(a, b / 2);
  tmp = tmp * tmp % mod;
  if (b & 1) {
    tmp = tmp * a % mod;
  }
  return tmp;
}

long long inv(long long a) {
  return power(a, mod - 2);
}

long long comb(int n, int k) {
  if (n < 0 || k < 0 || n < k) return 0;
  return fact[n] * ifact[k] % mod * ifact[n-k] % mod;
}

int main() {
  fact[0] = ifact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i % mod;
    ifact[i] = inv(fact[i]);
  }

  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  
  long long ab = 1;
  for (int i = 1; i <= min(a, b); i++) {
    ab += comb(a, i) * comb(b, i) % mod * fact[i];
    ab %= mod;
  } 

  long long bc = 1;
  for (int i = 1; i <= min(b, c); i++) {
    bc += comb(b, i) * comb(c, i) % mod * fact[i];
    bc %= mod;
  }

  long long ac = 1;
  for (int i = 1; i <= min(a, c); i++) {
    ac += comb(a, i) * comb(c, i) % mod * fact[i];
    ac %= mod;
  }


  cout << ab * bc % mod * ac % mod << endl;
  return 0;
}
