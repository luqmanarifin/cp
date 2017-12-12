/*

I will leave my heart at the door
I won't say a word
They've all been said before, you know
So why don't we just play pretend
Like we're not scared of what is coming next
Or scared of having nothing left

Look, don't get me wrong
I know there is no tomorrow

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again?

I don't need your honesty
It's already in your eyes
And I'm sure my eyes, they speak for me
No one knows me like you do
And since you're the only one that matters
Tell me who do I run to?

Let this be our lesson in love
Let this be the way we remember us
I don't wanna be cruel or vicious
And I ain't asking for forgiveness

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again? 

*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

char s[N];
int can[N][2], sum[N];
pair<int, int> dp[N];

int find(int l, int r) {
  return sum[r] - sum[l - 1];
}

int main() {
  int n, m;
  scanf("%d %s %d", &n, s + 1, &m);
  for (int i = 1; i <= n; i++) {
    sum[i] = sum[i - 1];
    if (s[i] == '?') sum[i]++;
  }
  if (m == 1) {
    cout << find(1, n) << endl;
    return 0;
  }
  for (int i = n; i >= 1; i--) {
    if (s[i] == '?') {
      can[i][0] = can[i+1][1] + 1;
      can[i][1] = can[i+1][0] + 1;
    } else if (s[i] == 'a') {
      can[i][1] = can[i+1][0] + 1;
    } else {
      can[i][0] = can[i+1][1] + 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = max(dp[i], dp[i - 1]);
    if (can[i][1] >= m) {
      dp[i+m-1] = max(dp[i+m-1], make_pair(dp[i-1].first + 1, dp[i-1].second - find(i, i + m - 1)));
    }
    //printf("%d: %d %d can %d %d\n", i, dp[i].first, -dp[i].second, can[i][0], can[i][1]);
  }
  cout << -dp[n].second << endl;
  return 0;
}
