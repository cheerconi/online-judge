#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    bool row = true, f = true;
    set<int> x;
    x.insert(0);
    set<int> y = x;
    for (char c : s) {
        if (c == 'F') cnt++;
        else {
            set<int> tmp;
            if (row) {
                for (int item : x) {
                    tmp.insert(item + cnt);
                    if (!f) tmp.insert(item - cnt);
                }
                swap(tmp, x);
            }
            else {
                for (int item : y) {
                    tmp.insert(item + cnt);
                    tmp.insert(item - cnt);
                }
                swap(tmp, y);
            }
            cnt = 0;
            row = !row;
            f = false;
        }
    }
    if (cnt != 0) {
        set<int> tmp;
        if (row) {
            for (int item : x) {
                tmp.insert(item + cnt);
                if (!f) tmp.insert(item - cnt);
            }
            swap(tmp, x);
        }
        else {
            for (int item : y) {
                tmp.insert(item + cnt);
                tmp.insert(item - cnt);
            }
            swap(tmp, y);
        }
    }
    if (x.find(a) != x.end() && y.find(b) != y.end()) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}