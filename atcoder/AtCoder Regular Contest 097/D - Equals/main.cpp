#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
int par[MAXN], nums[MAXN];
vector<int> idx[MAXN], val[MAXN];
int count(int i) {
    sort(idx[i].begin(), idx[i].end());
    sort(val[i].begin(), val[i].end());
    auto it1 = idx[i].begin();
    auto it2 = val[i].begin();
    int cnt = 0;
    while (it1 != idx[i].end() && it2 != val[i].end()) {
        if (*it1 == *it2) {
            cnt++;
            it1++;
            it2++;
        }
        else if (*it1 > *it2) it2++;
        else it1++;
    }
    return cnt;

}
int find(int i) {
    if (par[i] == i) return i;
    return par[i] = find(par[i]);
}
void add (int i,int j) {
    int a = find(i);
    int b = find(j);
    par[a] = b;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        par[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i++) {
        idx[find(i)].push_back(i);
        val[find(i)].push_back(nums[i]);
    }
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        tot += count(i);
    }
    cout << tot << endl;



    return 0;
}