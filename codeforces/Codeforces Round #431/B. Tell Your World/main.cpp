#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
const int MAXN = 1000 + 10;
int nums[MAXN];
int n;
bool check() {
    if (nums[1]-nums[0] == nums[2]-nums[1]) return true;
    return false;
}
bool check(int i, int j, int k) {
    LL x1 = i - j;
    LL x2 = i - k;
    LL y1 = nums[i] - nums[j];
    LL y2 = nums[i] - nums[k];
    if (x1*y2 == x2*y1) return true;
    return false;
}
bool check(vector<int> const & v, int a, int b) {
    if (v.size() == 0) return false;
    if (v.size() == 1) return true;
    LL x1 = a - b;
    LL x2 = v[0] - v[1];
    LL y1 = nums[a] - nums[b];
    LL y2 = nums[v[0]] - nums[v[1]];
    if (x1*y2 != x2*y1) return false;
    for (int i = 2; i < v.size(); i++) {
        if(!check(v[0], v[1], v[i])) return false;
    }
    return true;
}

bool solve (int a, int b, int c) {
    vector<int> other(1, a);
    for (int i = 3; i < n; i++) {
        if (!check(b, c, i)) other.push_back(i);
    }
    return check(other, b, c);
}

bool solve (int a, int b) {
    vector<int> other;
    for (int i = 2; i < n; i++) {
        if (!check(a, b, i)) other.push_back(i);
    }
    return check(other, a, b);
}

int main() {
//    freopen("test.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    bool flag = check();
    if (flag && n == 3) {
        cout << "No" << endl;
        return 0;
    }

    if (!flag) {
        if (solve(0, 1, 2)) cout << "Yes" << endl;
        else if (solve(1, 2, 0)) cout << "Yes" << endl;
        else if (solve(2, 1, 0)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        if (solve(0, 1)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}