#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 200000 + 10;
int ret[MAXN];
pii items[MAXN];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        items[i] = {val, i};
    }
    sort(items, items+n);
    for (int i = 0; i < n; i++) {
        int mid = n / 2;
        if (items[i].first >= items[mid].first) {
            mid--;
        }
        ret[items[i].second] = items[mid].first;
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i] << '\n';
    }


    return 0;
}