#include <iostream>
using namespace std;
typedef long long LL;

int main() {
    LL a, b;
    cin >> a >> b;
    LL ret = 1;
    for (LL i = a+1; i <= b; i++) {
        ret = ret * (i % 10);
        ret = ret % 10;
        if (ret == 0) break;
    }
    cout << ret << endl;
    return 0;
}