#include <iostream>
#include <algorithm>
using namespace std;
int nums[3];
int a1, a2, b1, b2;

bool solve() {
    sort(nums, nums+3);
    a1 = 0;
    a2 = nums[0];
    b1 = 0;
    b2 = nums[1];
    if (a2+b2 < nums[2]) return false;
    if ((a2+b2-nums[2]) % 2 == 1) return false;
    a1 = (a2+b2-nums[2]) / 2;
    b1 = a1;
    a2 -= a1;
    b2 -= b1;
    b2 = -b2;
    return true;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &nums[0], &nums[1], &nums[2]);
        if (solve()) {
            cout << 0 << ' ' << 0 << ' ' << a1 << ' ' << a2 << ' ' << b1 << ' ' << b2 << endl;
        }
        else cout << -1 << endl;

    }

}