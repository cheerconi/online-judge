#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> nums;
bool check (int a, int b) {
    if (a > b) swap(a, b);
    if (a % m != m-1 && a+1 == b) return true;
    if (a+m == b) return true;
    return false;
}
bool dfs(int i) {
    if (i == n*m) return true;
    for (int j = i; j < n*m; j++) {
        swap(nums[i], nums[j]);
        bool cur = true;
        if (i % m != 0 && check(nums[i-1], nums[i])) cur = false;
        if (i-m >= 0 && check(nums[i-m],nums[i])) cur = false;
        if (cur) {
            if (dfs(i+1)) return true;
        }
        swap(nums[i], nums[j]);
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    nums.resize(n*m);
    for (int i = 0; i < m*n; i++) {
        nums[i] = i;
    }
    if (dfs(0)) {
        cout << "YES" << endl;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << nums[idx++] + 1;
                if (j+1 != m) cout << ' ';
            }
            cout << endl;
        }
    }
    else cout << "NO" << endl;
}