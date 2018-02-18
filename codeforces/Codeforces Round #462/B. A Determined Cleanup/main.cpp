#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int main() {
//    freopen("test.txt", "r", stdin);
    LL p, k, carry = 0;
    cin >> p >> k;
    vector<LL> ret;
    int cnt = 0;
    while (p) {
        LL tmp = p % k;
        if (tmp < 0) tmp += k;
        ret.push_back(tmp);
        p = (tmp-p) / k;
        cnt++;
        if (cnt > 10000000) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }

    return 0;
}