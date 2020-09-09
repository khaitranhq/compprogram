#include <bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("data.inp", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int mmin, d, v, x, trip;
    cin >> d >> v >> x;

    mmin = (d + v - (d - v) * ((2 * (d - v) + 1) % 2)) / 2;
    mmin = (mmin + x - (mmin - x) * ((2 * (mmin - x) + 1) % 2)) / 2;
    // mmin = min({d, v, x})

    d -= mmin;
    v -= mmin;
    x -= mmin;

    trip = (d / 3 + v / 3 + x / 3);
    d %= 3;
    v %= 3;
    x %= 3;

    printf("%d", mmin + trip + (d + v + x) / 4);
}
