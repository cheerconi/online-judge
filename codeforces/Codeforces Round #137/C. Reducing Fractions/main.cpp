#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int MAXV = 1e7 + 10;
const int MAXN = 1e5  +10;
int factor[MAXV];
unordered_map<int, int> a, b;
int nums[2][MAXN];

void make_table() {
    for (LL i = 2; i < MAXV; i++) {
        if (factor[i] != 0) continue;
        for (LL j = i*i; j < MAXV; j += i) {
            if (factor[j] == 0) factor[j] = i;
        }
    }
}

void solve(int n, int v[], unordered_map<int, int > & t) {
    int val, div;
    for (int i = 0; i < n; i++) {
        val = v[i];
        div = 1;
        while (factor[val] != 0) {
            if (t[factor[val]] == 0) div *= factor[val];
            else t[factor[val]]--;
            val /= factor[val];
        }
        if (val > 1) {
            if (t[val] == 0) div *= val;
            else t[val]--;
        }
        v[i] = v[i] / div;
    }
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    make_table();
    int n, m, val;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> val; nums[0][i] = val;
        while (factor[val] != 0) {
            a[factor[val]]++;
            val /= factor[val];
        }
        if (val > 1) a[val]++;
    }
    for (int i = 0; i < m; i++) {
        cin >> val; nums[1][i] = val;
        while (factor[val] != 0) {
            if (a[factor[val]] > 0) a[factor[val]]--;
            else b[factor[val]]++;
            val /= factor[val];
        }
        if (val > 1) {
            if (a[val] > 0) a[val]--;
            else b[val]++;
        }
    }
    solve (n, nums[0], a);
    solve (m, nums[1], b);
    cout << n << ' ' << m << endl;
    for (int i = 0; i < n; i++) {
        cout << nums[0][i];
        if (i+1 == n) cout << endl;
        else cout << ' ';
    }
    for (int i = 0; i < m; i++) {
        cout << nums[1][i];
        if (i+1 == m)  cout << endl;
        else cout << ' ';
    }

    return 0;
}