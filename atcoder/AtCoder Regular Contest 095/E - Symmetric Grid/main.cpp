#include <iostream>
#include <memory.h>
#include <string>
using namespace std;
const int MAXN = 15;
string mat[MAXN];
int couple[MAXN], cnt[26];
bool used1, used2, vis[MAXN];
int n, m;

bool check (int i) {
    if (vis[i]) return check(i+1);
    if (i == m) return true;
    for (int j = i+1; j < m; j++) {
        if (vis[j]) continue;
        bool flag = true;
        for (int k = 0; k < n && flag; k++) {
            if (mat[k][i] != mat[couple[k]][j]) flag = false;
        }
        if (flag) {
            vis[i] = true;
            vis[j] = true;
            return check(i+1);
        }

    }
    if (m % 2 == 1 && !used2) {
        used2 = true;
        vis[i] = true;
        return check(i+1);
    }
    return false;
}

bool cmp(int i, int j) {
    memset(cnt, 0, sizeof(cnt));
    for (int k = 0; k < m; k++) {
        cnt[mat[i][k]-'a']++;
        cnt[mat[j][k]-'a']--;
    }
    for (int k = 0; k < 26; k++) {
        if (cnt[k] != 0) return false;
    }
    return true;

}

bool solve (int i) {
    if (couple[i] != -1) return solve(i+1);
    if (i == n) {
        memset(vis, false, sizeof(vis));
        used2 = false;
        return check(0);
    }
    if (n % 2 == 1 && !used1) {
        couple[i] = i;
        used1 = true;
        if (solve(i+1)) return true;
        used1 = false;
        couple[i] = -1;
    }
    for (int j = i+1; j < n; j++) {
        if (couple[j] != -1) continue;
        if (!cmp(i, j)) continue;
        couple[i] = j;
        couple[j] = i;
        if (solve(i+1)) return true;
        couple[i] = -1;
        couple[j] = -1;
    }
    return false;

}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mat[i];
    }
    memset(couple, -1, sizeof(couple));
    if (solve(0)) cout << "YES" << endl;
    else cout << "NO" << endl;


}