#include <iostream>
#include <algorithm>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    int left = INT_MAX;
    int right = -1;
    int top = INT_MAX;
    int bottom = -1;
    scanf("%d%d", &n, &m);
    char tmp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &tmp);
            if (tmp == 'B') {
                cnt++;
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }

        }
    }
    int len = max(right - left, bottom - top) + 1;
    if (len > n || len > m) cout << -1 << endl;
    else {
        cnt = len*len - cnt;
        cout << cnt << endl;
    }
    return 0;
}