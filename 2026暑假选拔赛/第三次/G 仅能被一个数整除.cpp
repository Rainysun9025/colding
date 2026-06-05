#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 i128;

ll n, m, k;
i128 lcm_val;

i128 count_valid(i128 x)
{
    return x / n + x / m - 2 * (x / lcm_val);
}

int check(i128 x)
{
    return count_valid(x) >= k;
}

int main()
{
    scanf("%lld%lld%lld", &n, &m, &k);
    ll g = __gcd(n, m);
    lcm_val = (i128)n / g * m;

    i128 left = 1;
    i128 right = 1;

    while (!check(right))
    {
        right *= 2;
    }

    while (left < right)
    {
        i128 mid = (left + right) / 2;

        if (check(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    printf("%lld\n", (ll)left);

    return 0;
}