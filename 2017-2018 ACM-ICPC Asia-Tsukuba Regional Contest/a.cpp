/**

Heart beats fast
Colours and promises
How to be brave?
How can I love when I'm afraid to fall?
But watching you stand alone,
All of my doubt suddenly goes away somehow.

One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

Time stands still
Beauty in all she is
I will be brave
I will not let anything take away
What's standing in front of me
Every breath
Every hour has come to this

One step closer
One step closer

I have died every day waiting for you
Darling, don't be afraid.
I have loved you for a thousand years
I'll love you for a thousand more

And all along I believed I would find you
Time has brought your heart to me
I have loved you for a thousand years
I'll love you for a thousand more

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 120;

long long dp[N][3];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  
  dp[k][2] = 1;
  dp[1][1] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i+1][1] += dp[i][0];
    dp[i+k][2] += dp[i][0];
    
    dp[i+1][0] += dp[i][1];
    
    dp[i+1][0] += dp[i][2];
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += dp[i][1] + dp[i][2];
  cout << ans << endl;
  return 0;
}
