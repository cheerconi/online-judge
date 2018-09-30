#include <iostream>
using namespace std;
const int MAXN = 1e5 + 10;
int nums[MAXN], op[MAXN];
int main () {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int cur = nums[n-1];
    for (int i = n-2; i >= 0; i--) {
        if (cur >= nums[i]) {
            op[i]++;
            op[i+1]--;
            cur -= nums[i];
        }
        else {
            op[i+1]++;
            cur = nums[i] - cur;
        }
    }
    for (int i = 0; i < n; i++) {
        op[i+1] += op[i];
        if (op[i]%2 == 0) cout << '+';
        else cout << '-';
    }
    cout << endl;
}