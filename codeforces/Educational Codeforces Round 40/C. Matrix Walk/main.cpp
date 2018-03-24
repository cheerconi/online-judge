#include <iostream>
using namespace std;
const int MAXN = 200000 + 10;
int nums[MAXN], geuss[MAXN], no[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    int x = 1e9, y = -1;
    for (int i = 0; i+1 < n; i++) {
        if (nums[i] == nums[i+1]) {
            cout << "NO" << endl;
            return 0;
        }
        geuss[i] = abs(nums[i] - nums[i+1]);
        if (geuss[i] == 1) {
            no[i] = min(nums[i], nums[i+1]);
        }
        else y = geuss[i];
    }
    if (y == -1) {
        y = 1e9;
    }
    else {
        for (int i = 0; i+1 < n; i++) {
            if (geuss[i] == y) continue;
            if (no[i] == 0 || no[i] % y == 0) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    cout << x << ' ' << y << endl;
    return 0;
}