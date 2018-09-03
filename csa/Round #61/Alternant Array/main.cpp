#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    freopen("test.txt", "r", stdin);
    int ret1 = 0, ret2 = 0;
    int n, val;
    cin >> n;
    for (int i = 0; i < n*2; i++) {
        cin >> val;
        if (val == 1) {
            if (i % 2 == 0) {
                ret1++;
            }
            else {
                ret2++;
            }
        }
        else {
            if (i % 2 == 0) {
                ret2++;
            }
            else {
                ret1++;
            }
        }
    }
    int ret = min(ret1, ret2) / 2;
    cout << ret << endl;
    return 0;
}