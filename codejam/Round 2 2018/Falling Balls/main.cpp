#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAXN = 200;
int nums[MAXN];
vector<string> ret;

bool solve(int c) {
    if (nums[0] == 0 || nums[c-1] == 0) return false;
    ret.clear();
    int i = 0;
    for (int k = 0; k < c; k++) {
        if (nums[k] == 0) continue;
        int j = i + nums[k] - 1;
        if (i < k) {
            for (int v = 0; v < k-i; v++) {
                if (ret.size() == v) ret.push_back(string(c, '.'));
                ret[v][i+v] = '\\';
            }
        }
        else if (i > k) {
            for (int v = 0; v < i-k; v++) {
                if (ret.size() == v) ret.push_back(string(c, '.'));
                ret[v][i-v] = '/';
            }
        }
        if (j < k) {
            for (int v = 0; v < k-j; v++) {
                if (ret.size() == v) ret.push_back(string(c, '.'));
                ret[v][j+v] = '\\';
            }
        }
        else if (j > k) {
            for (int v = 0; v < j-k; v++) {
                if (ret.size() == v) ret.push_back(string(c, '.'));
                ret[v][j-v] = '/';
            }
        }
        i = j + 1;
    }

    if (ret.empty() || ret.back() != string(c, '.')) ret.push_back(string(c, '.'));

    return true;
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int cs; cin >> cs;
    for (int k = 1; k <= cs; k++) {
        int c; cin >> c;
        for (int i = 0; i < c; i++) {
            cin >> nums[i];
        }
        cout << "Case #" << k << ": ";
        if (solve(c)) {
            cout << ret.size() << '\n';
            for (string & s : ret) {
                cout << s << '\n';
            }
        }
        else cout << "IMPOSSIBLE\n";


    }
    return 0;
}