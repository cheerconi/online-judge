#include <iostream>
#include <bitset>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    bitset<4000010> cur;
    cur[0] = 1;
    int val, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> val;
        cur |= cur<<val;
        sum += val;
    }
    for (int i = (sum+1)/2; i <= sum; i++) {
        if (cur[i]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;

}