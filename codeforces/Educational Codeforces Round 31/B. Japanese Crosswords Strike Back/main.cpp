#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    int n, x, val;
    LL sum = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        sum += val;
    }
    sum += n - 1;
    if (sum == x) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}