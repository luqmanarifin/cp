#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

long long phi(long long n)
{    
    long long result = n;   // Initialize result as n
 
    // Consider all prime factors of n and subtract their
    // multiples from result
    for (long long p=2; p*p<=n; ++p)
    {
        // Check if p is a prime factor.
        if (n % p == 0)
        {
            // If yes, then update n and result 
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
 
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
  long long n, k;
  scanf("%I64d %I64d", &n, &k);
  long long kali = (k + 1) / 2;
  long long now = n;
  for (int i = 0; i < kali; i++) {
    if (now == 1) break;
    now = phi(now);
  }
  cout << now % mod << endl;
  return 0;
}