#include <iostream>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp, cnt = 0;
    int pre = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tmp);
        if (i > pre && tmp == i) {
            cnt++;
            pre = i+1;
        }
    }
    if (pre < n && tmp == n) cnt++;
    cout << cnt << endl;

}