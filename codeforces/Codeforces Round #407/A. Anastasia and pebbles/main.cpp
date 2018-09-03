#include <iostream>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, tmp;
    scanf("%d%d", &n, &k);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp % k != 0) cnt++;
        cnt += tmp / k;
    }
    cnt = (cnt+1) / 2;
    cout << cnt << endl;
    return 0;
}