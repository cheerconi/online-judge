#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n, val;
    cin >> n;
    unordered_map<int, int> table;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        table[val]++;
    }
    int cnt = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second > it->first) {
            cnt += it->second - it->first;
        }
        else if (it->second < it->first) {
            cnt += it->second;
        }
    }
    cout << cnt << endl;
    return 0;
}