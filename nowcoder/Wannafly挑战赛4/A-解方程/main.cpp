#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<int> table;

bool solve(int x) {
    for (int a : table) {
        for (int b : table) {
            int c = -a*x*x - b*x;
            if (table.find(c) != table.end()) return true;
        }
    }
    return false;
}
int main() {
    int n, x, val;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        table.insert(val);
    }
    if (solve(x)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}