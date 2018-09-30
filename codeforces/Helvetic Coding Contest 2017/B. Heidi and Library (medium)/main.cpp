#include <vector>
#include <set>
#include <iostream>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> seq(n, 0);
    for (int i = 0; i < n; i++) scanf("%d", &seq[i]);
    vector<int> next(n, 0);
    vector<int> now(n+1, -1);
    for (int i = n-1; i >= 0; i--) {
        next[i] = now[seq[i]];
        now[seq[i]] = i;
    }
    set<int> pos;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (pos.count(i) == 0) {
            if (pos.size() == k) {
                pos.erase(--pos.end());
            }
            cnt++;
        }
        else {
            pos.erase(i);
        }
        if (next[i] != -1) pos.insert(next[i]);
    }
    cout << cnt << endl;

}