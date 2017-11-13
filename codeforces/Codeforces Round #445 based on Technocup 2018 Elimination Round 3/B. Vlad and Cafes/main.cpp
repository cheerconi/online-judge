#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, val;
    cin >> n;
    map<int, int> table;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        table[val] = i;
    }
    int idx = n, ret = 0;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second < idx) {
            idx = it->second;
            ret = it->first;
        }
    }
    cout << ret << endl;
    return 0;
}