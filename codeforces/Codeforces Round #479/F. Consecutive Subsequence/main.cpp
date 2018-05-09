#include <iostream>
#include <map>
using namespace std;
const int MAXN = 2e5 + 10;
int nums[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    map<int, int> table;
    for (int i = n-1; i >= 0; i--) {
        table[nums[i]] = table[nums[i]+1] + 1;
    }
    int start = -1, len = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second > len) {
            start = it->first;
            len = it->second;
        }
    }
    cout << len << endl;
    int cur = start;
    for (int i = 0; i < n; i++) {
        if (nums[i] == cur) {
            cout << i+1;
            len--;
            if (len == 0) cout << endl;
            else cout << ' ';
            cur++;
        }
    }
    return 0;
}