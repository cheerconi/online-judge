#include <iostream>
#include <math.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, a, b, ret;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ret = sqrt(b);
        int tmp = sqrt(a);
        if (tmp*tmp != a) {
            tmp++;
        }
        cout << ret - tmp + 1 << endl;
    }
    return 0;
}