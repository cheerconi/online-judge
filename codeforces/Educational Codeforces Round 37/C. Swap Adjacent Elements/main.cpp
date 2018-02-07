#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
int nums[MAXN], n;

bool solve (int a, int b) {
    if (a > n) return true;
    b++;
    b = min(b, n+1);
    sort(nums+a, nums+b);
    for (int i = a; i < b; i++) {
        if (nums[i] != i) return false;
    }
    return true;
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }
    string s; cin >> s;
    s = "x" + s;
    int i = 1;
    while (i < n) {
        while (i < n && s[i]=='0') {
            if (nums[i] != i) {
                cout << "NO" << endl;
                return 0;
            }
            i++;
        }
        int a = i;
        while (i < n && s[i] =='1') i++;
        int b = i;
        if (!solve(a, b)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}