#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
const int MAXN = 1e5 + 10;
int cost1[MAXN], cost0[MAXN];
int ind[MAXN];
int n, m, k;

bool cmp(int i, int j) {
    return (cost1[i]-cost0[i]) < (cost1[j] - cost0[j]);
}

int solve() {
    int sum = 0;
    if (m % 2 == 0) {
        if (k % 2 == 1) k++;
        k = k / 2;
        for (int i = 0; i < m / 2; i++) {
            sum += cost0[i];
        }
        sort(ind, ind+(m/2), cmp);
        for (int i = 0; i < k; i++) {
            sum += (cost1[ind[i]] - cost0[ind[i]]);
        }
        return sum;
    }

    // m % 2 == 1
    if (k % 2 == 0) {
        k = k / 2;
        for (int i = 0; i <= m/2; i++) {
            sum += cost0[i];
        }
        sort(ind, ind+(m/2), cmp);
        for (int i = 0; i < k; i++) {
            sum += (cost1[ind[i]] - cost0[ind[i]]);
        }
        return sum;
    }

    // m % 2 == 1 && k % 2 == 1
    k = k / 2;
    for (int i = 0; i <= m/2; i++) {
        sum += cost0[i];
    }
    sort(ind, ind+(m/2), cmp);
    for (int i = 0; i < k; i++) {
        sum += (cost1[ind[i]] - cost0[ind[i]]);
    }
    sum = min(sum+cost1[ind[k]]-cost0[ind[k]], sum+cost1[m/2]-cost0[m/2]);
    return sum;
}

int main() {
//    freopen("test.txt", "r", stdin);
    cin >> n >> m >> k;
    vector<vector<char> > mat(n, vector<char>(m, 0));

    for (int i = 0; i < n; i++) {
        getchar();
        for (int j = 0; j < m; j++) {
            scanf("%c", &mat[i][j]);
        }
    }
    for (int i = 0; i < (n+1)/2; i++) {
        for (int j = 0; j < (m+1)/2; j++) {
            int a = n - 1 - i;
            int b = m - 1 - j;
            if (mat[i][j] != mat[i][b]) {
                cost0[j] += 1;
            }
            if (i == a) {
                if (mat[i][j] != mat[i][b]) cost1[j]++;
                continue;
            }

            if (mat[a][j] != mat[a][b]) {
                cost0[j] += 1;
            }

            if (j == b) {
                if (mat[i][j] != mat[a][j]) cost1[j]++;
                continue;
            }


            map<char, int> tmp;
            tmp[mat[i][j]]++;
            tmp[mat[i][b]]++;
            tmp[mat[a][j]]++;
            tmp[mat[a][b]]++;
            int tmp2 = 0;
            for (auto it = tmp.begin(); it != tmp.end(); it++) {
                tmp2 = max(tmp2, it->second);
            }
            cost1[j] += 4 - tmp2;
        }
    }
    for (int i = 0; i < (m+1)/2; i++) {
        ind[i] = i;
    }
    cout << solve() << endl;
    return 0;
}