#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int length, n;
        int a = 0, b = 0, tmp;
        scanf("%d%d", &length, &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            a = max(a, min(tmp, length-tmp));
            b = max(b, tmp);
            b = max(b, length-tmp);
        }
        printf("%d %d\n", a, b);
    }
    return 0;
}