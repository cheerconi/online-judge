#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int a[100];
int idx[100];
int ret[100];
bool cmp(int i,int j) {
    return a[i] < a[j];
}
int main() {
    int n;
    cin >> n;
    set<int> table;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        idx[i] = i;
        table.insert(a[i]);
    }
    if (table.size() < n) {
        cout << -1 << endl;
        return 0;
    }
    sort(idx, idx+n, cmp);
    for (int i = 0; i < n; i++) {
        int c = idx[i];
        int d = idx[(i+1)%n];
        ret[c] = a[d];
    }
    for (int i = 0; i < n; i++) {
        cout << ret[i];
        if (i+1 == n) cout << endl;
        else cout << ' ';
    }

    return 0;
}