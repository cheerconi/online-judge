#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, len, val;
    cin >> n >> len;
    int ret = len;
    for (int i = 0; i < n; i++) {
        cin >> val;
        if (len % val == 0) {
            ret = min(ret, len/val);
        }
    }
    cout << ret << endl;
    return 0;
}