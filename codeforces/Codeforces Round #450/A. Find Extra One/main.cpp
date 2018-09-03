#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a, b, cnt = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);
        if (a > 0) cnt++;
    }
    if (cnt <= 1 || cnt >= n-1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}