#include <iostream>
#include <algorithm>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int cnt = 0, m = 0, tmp;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        if (tmp > m) cnt++;
        m = max(m, tmp);
    }
    cout << cnt << endl;
    return 0;
}