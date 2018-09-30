#include <iostream>
using namespace std;
int main() {
    int n, t, val;
    cin >> n >> t;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret++;
        cin >> val;
        t -= (86400 - val);
        if (t <= 0) break;
    }
    cout << ret << endl;

    return 0;
}