#include <iostream>
#include <set>
using namespace std;
const int MAXN = 300000 + 10;
int a[MAXN];
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, p;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    multiset<int> table;
    for (int i = 0; i < n; i++) {
        cin >> p;
        table.insert(p);
    }
    for (int i = 0; i < n; i++) {
        int num = 0, mask = 0;
        auto bk = table.begin();
        for (int j = 31; j >= 0; j--) {
            mask += 1<<j;
            if (a[i]&(1<<j)) {
                num += 1<<j;
            }
            auto it = table.lower_bound(num);
            if (it == table.end()) {
                num ^= (1<<j);
                continue;
            }
            int tmp = *it;
            tmp = tmp & mask;
            if (tmp^num) {
                num ^= 1<<j;
            }
            else {
                bk = it;
            }

        }
        num = *bk ^ a[i];
        cout << num;
        table.erase(bk);
        if (i+1 == n) cout << '\n';
        else cout << ' ';
    }

    return 0;
}