#include <iostream>
using namespace std;
const int MAXN = 100000 + 10;
int nums[MAXN];
bool solve(int n, int tot) {
    if (tot == 0) return false;
    if (tot == 1) return true;
    if (tot >= 3) {
        cout << "YES" << endl;
        for (int i = 0; i < n-3; i++) {
            cout << nums[i] << "->";
        }
        cout << "(0->0)->0" << endl;
        exit(0);
    }
    bool flag = false;
    for (int i = 0; i < n-2; i++) {
        if (nums[i] == 0) {
            flag = true;
            break;
        }
    }
    if (!flag) return false;
    cout << "YES" << endl;
    int i = 0;
    for (; i < n-2; i++) {
        if (nums[i] == 0) break;
        cout << nums[i] << "->";
    }
    cout << "(0->(";
    i++;
    for (; i < n-1; i++) {
        cout << nums[i];
        if (i+1 != n-1) cout << "->";
    }
    cout << "))->0" << endl;
    exit(0);

}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] == 0) tot++;
        else tot = 0;
    }
    if (!solve(n, tot)) cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << nums[i];
            if (i+1 == n) cout << endl;
            else cout << "->";
        }
    }

    return 0;
}