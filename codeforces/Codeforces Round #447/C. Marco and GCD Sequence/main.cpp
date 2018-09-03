#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1234;
int nums[MAXN];
vector<int> ret;

bool solve(int n) {
    int cnt = 0;
    int val = nums[0];
    while (cnt < n) {
        int pre = -1;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] == -1) continue;
            if (pre == -1 || pre % nums[i] == 0) {
                ret.push_back(nums[i]);
                pre = nums[i];
                nums[i] = -1;
                cnt++;
            }
        }
        if (ret.back() % val != 0) return false;
        ret.push_back(val);
    }
    return true;
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    if (solve(n)) {
        cout << ret.size() << endl;
        for (int i = 0; i < ret.size(); i++) {
            cout << ret[i];
            if (i+1 == ret.size()) cout << endl;
            else cout << ' ';
        }

    }
    else {
        cout << -1 << endl;
    }



    return 0;
}