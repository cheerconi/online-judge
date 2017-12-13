#include <iostream>
#include <unordered_set>
using namespace std;
unordered_set<int> table;
int a, b, c, ret = 1;
void solve () {
    int x = a * 10;
    int y = x / b;
    int z = x % b;
    if (y == c) {
        cout << ret << endl;
        exit(0);
    }
    table.insert(a);
    a = z;
    if (table.find(a) != table.end()) {
        cout << -1 << endl;
        exit(0);
    }
    ret++;
    solve();

}
int main() {
    cin >> a >> b >> c;
    solve();

    return 0;
}