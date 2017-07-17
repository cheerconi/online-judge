#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, tmp;
    scanf("%d", &n);
    map<int, vector<int> > pos;
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        pos[tmp].push_back(i);
    }
    LL trash = 0;
    LL lastround = 0;
    LL ret = 0;
    int now = 0;
    while (!pos.empty()) {
        vector<int> & v = pos.begin()->second;
        auto it = lower_bound(v.begin(), v.end(), now);
        if (it == v.end()) {
            ret += n - now - lastround;
            lastround = trash;
            now = 0;
        }
        else {
            ret += v.back() + 1 - now;
            now = v.back() + 1;
            trash += v.end() - it;
            v.erase(it, v.end());
            if (v.size() == 0) pos.erase(pos.begin());
        }
    }
    ret -= now - (trash - lastround);
    cout << ret << endl;

    return 0;
}