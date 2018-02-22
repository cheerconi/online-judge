#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n-i > 0 && (n-i)%i==0) cnt++;
    }
    cout << cnt << endl;
    return 0;
}