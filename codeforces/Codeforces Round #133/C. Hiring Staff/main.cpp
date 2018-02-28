#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 2000 + 10;
int cnt[MAXN];
int n, m;
void add(int i, int x) {
    cnt[i] += x;
    if (i+n < MAXN) cnt[i+n] -= x;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int k;
    vector<int> ret;
    cin >> n >> m >> k;
    for (int i = 0; i < n+m; i++) {
        if (cnt[i] < k) {
            for (int j = 0; j < k-cnt[i]; j++) ret.push_back(i);
            add(i, k-cnt[i]);
        }
        cnt[i+1] += cnt[i];
        if (cnt[i+1] == 0) {
            add (i, 1);
            cnt[i+1]++;
            ret.push_back(i);
        }
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i]+1;
        if (i+1 == ret.size()) cout << endl;
        else cout << ' ';
    }
    return 0;
}