#include <bits/stdc++.h>
#define MAX 300100
#define base 1000000009
typedef long long ll;

ll d1[MAX], d2[MAX], d3[MAX], f[MAX];
int n, m;

using namespace std;
void update(ll *bit, int x, int val)
{
    while (x <= n)
    {
        bit[x] += val;
        bit[x] %= base;
        x += x&(-x);
    }
}

ll getSum(ll *bit, int x)
{
    ll result = 0;
    while (x > 0)
    {
        result += bit[x];
        result %= base;
        x -= x&(-x);
    }
    return result;
}

#define nl puts("")

void print(ll *bit) {
	int i;
	for(i = 1; i <= n; ++i) printf("%lld ", bit[i]); nl;
}

int main()
{
//  freopen("446C.txt", "r", stdin);
    f[0] = 1; f[1] = 1;
    for (int i = 2; i < MAX; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % base;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        int x;
        scanf("%d", &x);
        update(d3, i, x);
    }
		print(d1);
		print(d2);
		print(d3);
    while (m--)
    {
        int t, l, r;
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1)
        {
            int v1, v2;
            if (l & 1)
            {
                v1 = -f[l];
                v2 = f[l + 1];
            }
            else
            {
                v1 = f[l];
                v2 = -f[l + 1];
            }

            update(d1, l, v1);
            update(d2, l, v2);
            update(d3, l, -1);

            ++r;
            update(d1, r, -v1);
            update(d2, r, -v2);
            update(d3, r, f[r - l + 1]);
        }
        else
        {
            --l;
				cout << getSum(d1, r) << ' ' << f[r + 4] << "asuasu" << '\n';
            ll ans = getSum(d1, r)*f[r + 4] + getSum(d2, r)*f[r + 3] + getSum(d3, r);
            ans -= getSum(d1, l)*f[l + 4] + getSum(d2, l)*f[l + 3] + getSum(d3, l);
            ans = ((ans % base) + base) % base;
            printf("%I64d\n", ans);
        }
		print(d1);
		print(d2);
		print(d3);
    }

    return 0;
}