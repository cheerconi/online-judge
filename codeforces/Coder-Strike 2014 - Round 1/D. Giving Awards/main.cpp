#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int MAXN = 3e4 + 10;
unordered_set<int> nxt[MAXN];

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        nxt[a].insert(b);
    }
    vector<int> ret;
    for (int i = 1; i <= n; i++) {
        ret.push_back(i);
        int j = ret.size()-1;
        while (j-1 >= 0 && nxt[ret[j-1]].find(ret[j]) != nxt[ret[j-1]].end()) {
            swap(ret[j-1], ret[j]);
            j--;
        }
    }
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i];
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }
}

