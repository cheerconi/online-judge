#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v;
    int n, k, val;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> val;
        v.push_back(val);
    }
    sort(v.begin(), v.end());
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += v[i];
    }
    int ret = 0;
    ret = cnt / 100;
    if (cnt % 100 != 0) ret++;
    cout << ret << endl;

    return 0;
}