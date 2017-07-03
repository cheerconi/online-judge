#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    scanf("%d%d", &n, &m);
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> ret;
    int len = n+1;
    for (int i = 0; i < m; i++) {
        if (i+n >= m+1) break;
        vector<int> tmp;
        for (int j = 0; j < n; j++) {
            if (s[j] != t[i+j]) {
                tmp.push_back(j);
            }
        }
        if (tmp.size() < len) {
            len = tmp.size();
            tmp.swap(ret);
        }
    }
    cout << len << endl;
    if (len == 0) return 0;
    for (int pos : ret) {
        cout << pos+1 << ' ';
    }
    cout << endl;
    return 0;
}