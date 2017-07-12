#include <iostream>
using namespace std;

int main() {
    int n, k;
    bool flag = true;
    scanf("%d%d", &n, &k);
    int cnt = n - 1;
    int ret = 0;
    if (cnt % k == 0) {
        ret = (cnt/k) << 1;
    }
    else if (cnt % k == 1) {
        ret = ((cnt/k) << 1) | 1;
    }
    else ret = (cnt/k + 1) << 1;
    printf("%d\n", ret);
    for (int i = 2; i <= k+1; i++) {
        printf("1 %d\n", i);
    }
    for (int i = k+2; i <= n; i++) {
        printf("%d %d\n", i-k, i);
    }


}