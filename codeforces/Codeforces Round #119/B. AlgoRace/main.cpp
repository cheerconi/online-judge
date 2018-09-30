#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
struct Quest{
    int s, t, k, ret, id;
    bool operator< (const Quest & oth) const {
        return k < oth.k;
    }
};
const int MAXN = 65;
const int MAXQ = 1e5 + 10;
int dp[MAXN][MAXN], dist[MAXN][MAXN], cur[MAXN][MAXN];
Quest q[MAXQ];

void floyd(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                if (cur[j][i]+cur[i][k] < cur[j][k]){
                    cur[j][k] = cur[j][i] + cur[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dist[i][j]== -1 || dist[i][j] > cur[i][j]){
                dist[i][j] = cur[i][j];
            }
        }
    }
}
void solve(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cur[i][j] = dp[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                dp[i][j] = min(cur[i][k]+dist[k][j], dp[i][j]);
            }
        }
    }
}
bool cmp(const Quest & a, const Quest & b){
    return a.id < b.id;
}
int main(){
//    freopen("test.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof(dist));
    int n, m, r, s, t, k;
    cin >> n >> m >> r;
    for (int k = 0; k < m; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++){
                cin >> cur[i][j];
            }
        }
        floyd(n);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = dist[i][j];
        }
    }
    for (int i = 0; i < r; i++){
        cin >> s >> t >> k; s--; t--;
        q[i].s = s; q[i].t = t; q[i].k = k; q[i].id = i;
    }
    sort(q, q+r);
    int idx = 0;
    for (int i = 0; i <= q[r-1].k; i++){
        while (idx < r && q[idx].k == i){
            q[idx].ret = dp[q[idx].s][q[idx].t];
            idx++;
        }
        if (idx == r) break;
        solve(n);
    }
    sort(q, q+r, cmp);
    for (int i = 0; i < r; i++){
        cout << q[i].ret << '\n';
    }

}
