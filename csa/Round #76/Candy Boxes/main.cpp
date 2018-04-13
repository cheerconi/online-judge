#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, cmd, val, cnt = 0;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    vector<int> ret;
    while (q--) {
        cin >> cmd;
        if (cmd == 1) {
            cin >> val;
            nums[val]--;
            if (nums[val] == -1) {
                nums[val] = 0;
                ret.push_back(val);
            }
        }
        else cnt++;
    }
    while (ret.size() != cnt) {
        ret.push_back(1);
    }
    for (int i = 0; i < cnt; i++) {
        cout << ret[i] << endl;
    }
    return 0;

}