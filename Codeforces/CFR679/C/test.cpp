#include <bits/stdc++.h>
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd
#define ll long long
const ll MAXN = 10, MAXA = 10, MAXB = 30;
ll n, m;
 
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for(int iTest = 1; iTest <= 1000; iTest++)
    {
        ofstream inp("data.inp");
        for (int i = 1; i <= 6; ++i)
          inp << Rand(1, MAXA) << " ";
        inp << "\n";
        int n = Rand(1, MAXN);
        inp << n << "\n";
        for (ll i = 1; i <= n; ++i)
          inp << Rand(MAXA + 1, MAXB) << " ";
        inp.close();

        system("./data");
        system("./data_t");
        if(system("cmp data.out data.ans") != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
