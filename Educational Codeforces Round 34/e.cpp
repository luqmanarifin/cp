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

const long long PRIME = 89;
const long long MOD = (long long) 1e9 + 4207;
const int N = 5005;

long long power[N];
char s[N][N];
vector<long long> ada[N];
long long ori[N];

int main() {
  power[0] = 1;
  for (int i = 1; i < N; i++) {
    power[i] = power[i - 1] * PRIME % MOD;
  }
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", s[i]);
  for (int i = 0; i < n; i++) {
    long long now = 0;
    for (int j = 0; j < m; j++) {
      now += (s[i][j] - 'a' + 1) * power[j]; 
      now %= MOD;
    }
    ori[i] = now;
    bool same = 0;
    for (int j = 0; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        if (s[i][j] == s[i][k]) {
          if (same) continue;
          same = 1;
        }
        long long cur = now;
        
        cur += (s[i][j] - 'a' + 1) * power[k] - (s[i][j] - 'a' + 1) * power[j];
        cur += (s[i][k] - 'a' + 1) * power[j] - (s[i][k] - 'a' + 1) * power[k];
        cur %= MOD;
        
        if (cur < 0) cur += MOD;
        ada[i].push_back(cur);
      }
    }
  }
  set<long long> v;
  for (auto it : ada[0]) v.insert(it);
  for (int i = 1; i < n; i++) {
    set<long long> nex;
    for (auto it : ada[i]) if (v.count(it)) {
      nex.insert(it);
    }
    v = nex;
    if (nex.empty()) {
      puts("-1");
      return 0;
    }
  }
  long long ans = *(v.begin());
  for (int j = 0; j < m; j++) {
    for (int k = j + 1; k < m; k++) {
      long long cur = ori[0];
      int i = 0;
      cur += (s[i][j] - 'a' + 1) * power[k] - (s[i][j] - 'a' + 1) * power[j];
      cur += (s[i][k] - 'a' + 1) * power[j] - (s[i][k] - 'a' + 1) * power[k];
      cur %= MOD;
      
      if (cur < 0) cur += MOD;
      
      if (cur == ans) {
        swap(s[0][j], s[0][k]);
        printf("%s\n", s[0]);
        return 0;
      }
    }
  }
  assert(0);
  return 0;
}
