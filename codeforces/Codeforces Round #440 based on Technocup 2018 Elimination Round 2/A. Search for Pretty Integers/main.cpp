#include <iostream>
#include <algorithm>
using namespace std;
bool a[10], b[10];

int solve () {
    for (int i = 1; i < 10; i++) {
        if (a[i] && b[i]) return i;
    }
    int a1 = 9;
    for (int i = 1; i < 9; i++) {
        if (a[i]) {
            a1 = i;
            break;
        }
    }
    int b1 = 9;
    for (int i = 1; i < 9; i++) {
        if (b[i]) {
            b1 = i;
            break;
        }
    }
    int ret = a1*10 + b1;
    ret = min(ret, b1*10 + a1);
    return ret;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m, val;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> val;
        a[val] = true;
    }
    for (int i = 0; i < m; i++) {
        cin >> val;
        b[val] = true;
    }
    cout << solve() << endl;

    return 0;
}