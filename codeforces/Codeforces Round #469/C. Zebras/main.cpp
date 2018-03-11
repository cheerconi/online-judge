#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
typedef vector<int> vi;

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<vi> ret;
    queue<int> one, zero;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (one.empty()) {
                ret.push_back(vi(1, i));
                zero.push(ret.size()-1);
            }
            else {
                int idx = one.front(); one.pop();
                ret[idx].push_back(i);
                zero.push(idx);
            }
        }
        else {
            if (zero.empty()) {
                cout << -1 << endl;
                return 0;
            }
            int idx = zero.front(); zero.pop();
            ret[idx].push_back(i);
            one.push(idx);
        }
    }
    if (!one.empty()) {
        cout << -1 << endl;
        return 0;
    }
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i].size();
        for (int j = 0; j < ret[i].size(); j++) {
            cout << ' ' << ret[i][j]+1;
        }
        cout << '\n';
    }

}