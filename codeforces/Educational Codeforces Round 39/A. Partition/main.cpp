#include <iostream>
#include <unordered_set>
#include <climits>
using namespace std;
const int MAXN = 123;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, sum = 0, val;
    cin >> n;
    unordered_set<int> table;
    table.insert(0);
    for (int i = 0; i < n; i++) {
        cin >> val;
        sum += val;
        auto tmp = table;
        for (int item : table) {
            tmp.insert(item+val);
        }
        swap(tmp, table);
    }
    int ret = INT_MIN;
    for (int item : table) {
        ret = max(2*item - sum, ret);
    }
    cout << ret << endl;

    return 0;
}