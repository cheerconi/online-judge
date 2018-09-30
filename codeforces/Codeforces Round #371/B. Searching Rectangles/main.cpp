#include <iostream>
using namespace std;
typedef long long LL;
LL x11, y11, x12, y12, x21, y21, x22, y22;
LL nums[4];
int ask(LL a, LL b, LL c, LL d) {
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << endl;
    int ret; cin >> ret;
    return ret;
}
void bin_search(int idx, LL  left, LL  right, bool one) {
    int ret;
    while (left < right) {
        LL mid = (left+right);
        if (idx <= 1) mid++;
        mid >>= 1;
        nums[idx] = mid;
        ret = ask(nums[0], nums[1], nums[2], nums[3]);
        if (!one) {
            if (nums[0] <= x11 && nums[1] <= y11 && x12 <= nums[2] && y12 <= nums[3]) {
                ret--;
            }
        }
        if (ret == 0) {
            if (idx <= 1) {
                right = mid - 1;
            }
            else {
                left = mid+1;
            }
        }
        else {
            if (idx <= 1) {
                left = mid;
            }
            else {
                right = mid;
            }
        }
    }
    nums[idx] = left;

}
void solve1(LL a, LL b, LL c, LL d) {
    nums[0] = a; nums[1] = b; nums[2] = c; nums[3] = d;
    bin_search(0, nums[0], nums[2], true);
    bin_search(1, nums[1], nums[3], true);
    bin_search(2, nums[0], nums[2], true);
    bin_search(3, nums[1], nums[3], true);
    x11 = nums[0]; y11 = nums[1]; x12 = nums[2]; y12 = nums[3];
}
void solve2(LL a, LL b, LL c, LL d) {
    nums[0] = a; nums[1] = b; nums[2] = c; nums[3] = d;
    bin_search(0, nums[0], nums[2], false);
    bin_search(1, nums[1], nums[3], false);
    bin_search(2, nums[0], nums[2], false);
    bin_search(3, nums[1], nums[3], false);
    x21 = nums[0]; y21 = nums[1]; x22 = nums[2]; y22 = nums[3];
}
int main() {
    LL n; cin >> n;
    LL a = 1, b = 1, c = n, d = n;
    int ret;
    LL left = a, right = c;
    while(left < right) {
        LL mid = (left+right + 1) >> 1;
        ret = ask(mid, b, c, d);
        if (ret == 0) {
            right = mid-1;
            continue;
        }
        if (ret == 2) {
            left = mid;
            continue;
        }
        solve1(mid, b, c, d);
        solve2(1, 1, n, n);
        cout << "! " << x11 << ' ' << y11 << ' ' << x12 << ' ' << y12 << ' ';
        cout << x21 << ' ' << y21 << ' ' << x22 << ' ' << y22 << endl;
        return 0;
    }
    a = left;
    left = a, right = c;
    while(left < right) {
        LL mid = (left+right) >> 1;
        ret = ask(a, b, mid, d);
        if (ret == 0) {
            left = mid+1;
            continue;
        }
        if (ret == 2) {
            right = mid;
            continue;
        }
        solve1(a, b, mid, d);
        solve2(1, 1, n, n);
        cout << "! " << x11 << ' ' << y11 << ' ' << x12 << ' ' << y12 << ' ';
        cout << x21 << ' ' << y21 << ' ' << x22 << ' ' << y22 << endl;
        return 0;
    }
    c = left;
    left = b, right = d;
    while(left < right) {
        LL mid = (left+right + 1) >> 1;
        ret = ask(a, mid, c, d);
        if (ret == 0) {
            right = mid-1;
            continue;
        }
        if (ret == 2) {
            left = mid;
            continue;
        }
        solve1(a, mid, c, d);
        solve2(1, 1, n, n);
        cout << "! " << x11 << ' ' << y11 << ' ' << x12 << ' ' << y12 << ' ';
        cout << x21 << ' ' << y21 << ' ' << x22 << ' ' << y22 << endl;
        return 0;
    }
    b = left;
    left = b, right = d;
    while(left < right) {
        LL mid = (left+right) >> 1;
        ret = ask(a, b, c, mid);
        if (ret == 0) {
            left = mid+1;
            continue;
        }
        if (ret == 2) {
            right = mid;
            continue;
        }
        solve1(a, b, c, mid);
        solve2(1, 1, n, n);
        cout << "! " << x11 << ' ' << y11 << ' ' << x12 << ' ' << y12 << ' ';
        cout << x21 << ' ' << y21 << ' ' << x22 << ' ' << y22 << endl;
        return 0;
    }
    d = left;
    cout << "! " << a << ' ' << b << ' ' << c << ' ' << d << ' ';
    cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    return 0;
}