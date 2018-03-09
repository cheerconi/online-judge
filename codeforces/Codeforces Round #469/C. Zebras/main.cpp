#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
const int MAXN =  200000 + 10;
set<int> ones, zeros;
vector<vi> ret;

bool solve () {
    if (ones.empty()) {
        auto it = zeros.begin();
        while (it != zeros.end()) {
            ret.push_back(vi(1, *it));
            zeros.erase(it++);
        }
        return true;
    }
    if (zeros.empty()) return false;
    if (*zeros.begin() > *ones.begin()) return false;
    ret.push_back(vi());
    ret.back().push_back(*zeros.begin());
    zeros.erase(zeros.begin());
    int need = 1;
    while (true) {
        int num = ret.back().back();
        if (need == 1) {
            auto it = ones.lower_bound(num);
            if (it == ones.end()) break;
            ret.back().push_back(*it);
            ones.erase(it);
            need = 0;
        }
        else {
            auto it = zeros.lower_bound(num);
            if (it == zeros.end()) break;
            ret.back().push_back(*it);
            zeros.erase(it);
            need = 1;
        }
    }
    if (need == 0) {
        int num = ret.back().back();
        ret.back().pop_back();
        ones.insert(num);
    }
    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') ones.insert(i);
        else zeros.insert(i);
    }
    while (!ones.empty() || !zeros.empty()) {
        if (!solve()) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ret.size() << '\n';
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i].size();
        for (int num : ret[i]) {
            cout << ' ' << num+1;
        }
        cout << '\n';
    }

    return 0;
}