#include <bits/stdc++.h>
using namespace std;
const string NAME = "data";
// Số test kiểm tra
const int NTEST = 1000;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd

// Viết lại hàm random để sử dụng cho thuận tiện. Hàm random này sinh ngẫu nhiên
// số trong phạm vi long long, số sinh ra >= l và <= h.
long long Rand(long long l, long long h) {
  assert(l <= h);
  return l + rd() * 1LL * rd() % (h - l + 1);
}

int main() {
  srand(time(NULL));
  for (int iTest = 1; iTest <= NTEST; iTest++) {
    ofstream inp(("./" + NAME + ".inp").c_str());
    for (int i = 1; i <= 6; ++i) inp << Rand(-5, 5) << " ";
    inp << Rand(1, 7) << " ";
    inp << Rand(1, 100);
    inp.close();
    // Nếu dùng Linux thì "./" + Tên chương trình
    system(("./" + NAME + ".exe").c_str());
    system(("./" + NAME + "_t.exe").c_str());
    // Nếu dùng linux thì thay fc bằng diff
    if (system(("diff ./" + NAME + ".out ./" + NAME + ".ans").c_str()) != 0) {
      cout << "Test " << iTest << ": WRONG!\n";
      return 0;
    }
    cout << "Test " << iTest << ": CORRECT!\n";
  }
  return 0;
}
