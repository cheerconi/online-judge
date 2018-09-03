#include <iostream>
using namespace std;
int a[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nums[30];
int n;

bool solve(int i) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
        int k = (i+j)%12;
        if (a[k] == 0) {
            if (nums[j] != 28 && nums[j] != 29) return false;
            cnt += nums[j];
            if (cnt == 29 * 2) return false;
        }
        else {
            if (a[k] != nums[j]) return false;
        }
    }
    return true;
}
int main() {

    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    bool flag = false;
    for (int i = 0; i < 12; i++) {
        if (solve(i)) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}