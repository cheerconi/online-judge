#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, val;
    cin >> n;
    int cnt[2] = {};
    for (int i = 0; i < n; i++) {
        cin >> val;
        cnt[val-1]++;
    }
    int ret = min(cnt[0], cnt[1]);
    cnt[0] -= ret;
    ret += cnt[0]/3;
    cout << ret << endl;

    return 0;
}