#include <iostream>
#include <string>
#include <unordered_map>
#include <memory.h>
using namespace std;
const int MAXN = 100000 + 10;
string ans[MAXN];
string sz[] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int cnt[6], tag[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    unordered_map<string, int> table;
    for (int i = 0; i < 6; i++) {
        cin >> cnt[i];
        table[sz[i]] = i;
    }
    int n, idx, id;
    cin >> n;
    string s;
    memset(tag, -1, sizeof(tag));
    for (int i = 0; i < n; i++) {
        cin >> s;
        idx = -1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ',') {
                idx = j;
                break;
            }
        }
        if (idx == -1) {
            id = table[s];
            if (cnt[id] == 0) {
                cout << "NO" << endl;
                return 0;
            }
            cnt[id]--;
            ans[i] = s;
        }
        else {
            id = table[s.substr(0, idx)];
            tag[i] = id;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < n && cnt[i] != 0; j++) {
            if (tag[j] == -1) continue;
            if (tag[j]+1 != i) continue;
            ans[j] = sz[i];
            cnt[i]--;
            tag[j] = -1;
        }
        for (int j = 0; j < n && cnt[i] != 0; j++) {
            if (tag[j] != i) continue;
            ans[j] = sz[i];
            cnt[i]--;
            tag[j] = -1;
        }

    }
    for (int i = 0; i < n; i++) {
        if (tag[i] != -1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}