#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long LL;
int x, d;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> x >> d;
    vector<LL> ret;
    LL cur = 1;
    while (x > 1) {
        for (int i = 30; i >= 0; i--) {
            if (x & (1<<i)) {
                for (int j = 0; j < i; j++) {
                    ret.push_back(cur);
                }
                x = x - (1<<i) + 1;
                cur += d;
                break;
            }
        }
    }
    if (x == 1) {
        ret.push_back(cur);
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }

    return 0;
}