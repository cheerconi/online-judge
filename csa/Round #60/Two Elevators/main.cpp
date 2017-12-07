#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int state[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, e1, e2, a, b;
    cin >> n >> e1 >> e2;
    for (int i = 0; i < n; i++){
        scanf("%d%d", &a, &b);
        if (a > b) {
            if (e1 >= a) {
                state[i] |= 1<<3;
            }
            if (e2 >= a) {
                state[i] |= 1<<1;
            }
        }
        else {
            if (e1 <= a) {
                state[i] |= 1<<2;
            }
            if (e2 <= a) {
                state[i] |= 1;
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 2; j < 4; j++) {
            int cur = 0;
            for (int k = 0; k < n; k++) {
                if ((state[k]&(1<<i)) || (state[k]&(1<<j))) cur++;
            }
            ret = max(ret, cur);
        }
    }
    cout << ret << endl;
    return 0;
}