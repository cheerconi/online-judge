#include <iostream>
using namespace std;
typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    int tmp = n;
    int cnt2 = 0, cnt5 = 0;
    while (n % 2 == 0) {
        n = n / 2;
        cnt2++;
    }
    while (n % 5 == 0) {
        n = n / 5;
        cnt5++;
    }
    LL ret = tmp;
    while (cnt2 < k) {
        ret *= 2;
        cnt2++;
    }
    while (cnt5 < k) {
        ret *= 5;
        cnt5++;
    }
    cout << ret << endl;

    return 0;
}