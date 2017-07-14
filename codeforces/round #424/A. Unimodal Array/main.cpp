#include <iostream>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int pre = 0, now;
    int state = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &now);
        if (now == pre && state <= 1) {
            state = 1;
            continue;
        }
        if (now == pre && state == 2) {
            cout << "NO" << endl;
            return 0;
        }
        if (now < pre) {
            state = 2;
            pre = now;
            continue;
        }
        if (now > pre && state >= 1) {
            cout << "NO" << endl;
            return 0;
        }
        if (now > pre && state == 0) {
            pre = now;
            continue;
        }

    }
    cout << "YES" << endl;
    return 0;
}