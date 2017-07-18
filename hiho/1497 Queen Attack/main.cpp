#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
typedef long long LL;

LL combine(LL n) {
    if (n == 1) return 0;
    return n*(n-1) >> 1;
}

LL cnt(unordered_map<int, vector<int> > const & m) {
    LL ret = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        ret += combine(it->second.size());
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, x, y;
    scanf("%d", &n);
    unordered_map<int, vector<int> > col;
    unordered_map<int, vector<int> > row;
    unordered_map<int, vector<int> > slash;
    unordered_map<int, vector<int> > diag;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &x, &y);
        row[x].push_back(i);
        col[y].push_back(i);
        slash[x+y].push_back(i);
        diag[x-y].push_back(i);
    }
    LL ret = 0;
    ret += cnt(col);
    ret += cnt(row);
    ret += cnt(slash);
    ret += cnt(diag);
    cout << ret << endl;




    return 0;
}