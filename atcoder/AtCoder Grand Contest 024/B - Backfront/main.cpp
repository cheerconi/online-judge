#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    unordered_map<int, int> table;
    int val, cur = 0, pos = n+1;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        table[val] = i;
    }
    int ret = 0;
    for (int i = n; i >= 1; i--) {
        if (table[i] < pos) {
            cur++;
            ret = max(cur, ret);
        }
        else cur = 1;
        pos = table[i];
    }
    cout << n - ret << endl;


    return 0;
}