#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
 
    int t;
    //double x, y, n;
    int x, y, n, c;
    cin >> t;
    while (t--) {
        cin >> x >> y >> n;
        if (n <= x) {
            cout << n * 3 << endl;
            continue;
        }
        //cout << (ceil(n / (x + y)) * (int)(x) * 3) << endl;
        for (c = 1; c <= n; c++) {
            if ((c * (x + y)) >= n)
                break;
        }
        cout << c * x * 3 << endl;
    }
 
    return 0;
}
