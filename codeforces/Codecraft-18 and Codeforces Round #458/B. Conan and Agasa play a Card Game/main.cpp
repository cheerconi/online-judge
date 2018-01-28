#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    int n;  cin >> n;
    unordered_map<int, int> table;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        table[val]++;
    }
    bool flag = false;
    for (auto it = table.begin(); it != table.end(); it++) {
        if (it->second % 2 != 0) {
            flag = true;
            break;
        }
    }
    if (flag) cout << "Conan" << endl;
    else cout << "Agasa" << endl;

    return 0;
}