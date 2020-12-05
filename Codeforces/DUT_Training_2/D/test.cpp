#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
// Tên chương trình
const string NAME = "data";
// Số test kiểm tra
const int NTEST = 1000, MAXN = 5, MAXA = 10;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        inp << "1\n";
        long long n = Rand(2, MAXN);
        inp << n << "\n";
        for (long long i = 1; i <= n; ++i)
          inp << Rand(0, MAXA) << " ";
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system("./data");
        system("./data_t");
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("diff " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
