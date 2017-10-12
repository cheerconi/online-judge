#include <iostream>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, x;
    cin >> n >> k >> x;
    int cnt = 0, tmp;
    for (int i = 0; i < n-k; i++) {
        cin >> tmp;
        cnt += tmp;
    }
    cnt += k * x;
    cout << cnt << endl;

    return 0;
}