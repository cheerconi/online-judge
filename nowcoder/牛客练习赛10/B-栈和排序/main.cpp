#include <iostream>
#include <stack>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int cur = n, val, tot = 0;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        cin >> val;
        s.push(val);
        while (!s.empty() && s.top() == cur) {
            cout << cur--;
            s.pop();
            tot--;
            if (tot == 0) cout << endl;
            else cout << ' ';
        }
    }
    while (!s.empty()) {
        cout << s.top();
        s.pop();
        if (s.empty()) cout << endl;
        else cout << ' ';
    }
    return 0;
}