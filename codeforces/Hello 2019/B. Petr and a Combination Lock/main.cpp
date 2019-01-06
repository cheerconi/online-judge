#include <iostream>
#include <set>
using namespace std;
int main() {
    int n; cin >> n;
    set<int> cur;
    cur.insert(0);
    for (int i = 0; i < n; i++) {
        set<int> nxt;
        int val; cin >> val;
        for (auto num : cur) {
            nxt.insert((num+val)%360);
            nxt.insert((num-val + 360)%360);
        }
        swap(nxt, cur);
    }
    for (auto num : cur) {
        if (num % 360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}