#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve(vector<int> data) {
    vector<int> gap;
    for (int i = 0; i+1 < data.size(); i++) {
        gap.push_back(data[i+1]-data[i]);
    }
    sort(gap.begin(), gap.end(), greater<int>());
    int tmp = 0;
    if (gap.size() > 1) {
        tmp = gap[1];
    }
    int ret = max(tmp, (gap[0]+1)/2);
    return ret;

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int val;
    vector<int> data;
    for (int i = 0; i < n; i++) {
        cin >> val;
        data.push_back(val);
    }
    int bk = data.back();
    data.pop_back();
    int ret = solve(data);
    data.erase(data.begin());
    data.push_back(bk);
    ret = min(ret, solve(data));
    cout << ret << endl;

}
