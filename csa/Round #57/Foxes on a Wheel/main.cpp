#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int state[MAXN];
int main() {
    int n, k, val;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        scanf("%d", &val);
        state[val-1] = 1;
    }
    for (int i = 0; i < k; i++) {
        scanf("%d", &val);
        state[val-1] = -1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (state[i] == -1) {
            int j = i - 1;
            if (j == -1) j += n;
            if (state[j] == 1) {
                cnt++;
                state[j] = 0;
            }
            else {
                if (state[(i+1) % n] == 1) {
                    cnt++;
                    state[(i+1) % n] = 0;
                }
            }
        }
    }
    cnt += (k - cnt) * 2;
    cout << cnt << endl;
    return 0;
}