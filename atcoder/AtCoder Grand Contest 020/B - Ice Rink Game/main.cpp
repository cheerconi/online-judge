#include <iostream>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
int nums[MAXN];
LL lft, rght;
bool solve(LL a) {
    LL tmp = lft / a * a;
    if (lft % a != 0) tmp += a;
    if (tmp > rght) return false;
    lft = tmp;
    tmp = rght / a * a;
    rght = tmp + a - 1;
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    lft = rght = 2;
    for (int i = n-1; i >= 0; i--) {
        if (!solve(nums[i])) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << lft << ' ' << rght << endl;

    return 0;
}