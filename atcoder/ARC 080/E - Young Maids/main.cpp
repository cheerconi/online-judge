#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> pii;

const int MAXN = 100000 + 10;
int num0[MAXN], num1[MAXN];
int dp0[MAXN][18], dp1[MAXN][18];
int n;
vector<int> sons[MAXN];
int degree[MAXN];
vector<pii> ret;

struct cmp {
    bool operator() (int a, int b) {
        if (ret[a].first != ret[b].first) return ret[a].first < ret[b].first;
        return ret[a].second < ret[b].second;
    }
};
set<int, cmp> cur;

void make_st(int dp[MAXN][18], int num[]) {
    for (int i = 0; i < n; i++) dp[i][0] = i;
    for (int j = 1; j < 18; j++) {
        for (int i = 0; i < n; i++) {
            if (i+(1<<j)-1 >= n) break;
            int pos1 = dp[i][j-1];
            int pos2 = dp[i+(1<<(j-1))][j-1];
            if (num[pos1] > num[pos2]) dp[i][j] = pos2;
            else dp[i][j] = pos1;
        }
    }
}
int findmin(int dp[MAXN][18], int num[], int a, int b) {
    int length = b - a + 1;
    int j = -1;
    while (length != 0) {
        j++;
        length /= 2;
    }
    int pos1 = dp[a][j];
    int pos2 = dp[b+1-(1<<j)][j];
    if (num[pos1] > num[pos2]) return pos2;
    return pos1;
}

void solve(int a, int b, int fa) {
    if (a > b) return;
    if (a % 2 == 0) {
        int x = findmin(dp0, num0, a/2, b/2);
        int y = findmin(dp1, num1, x, b/2);
        ret.push_back({num0[x], num1[y]});
        int now = ret.size() - 1;
        if (fa != -1) {
            sons[fa].push_back(now);
            degree[now]++;
        }
        else cur.insert(now);
        solve(a, 2*x-1, fa);
        solve(2*x+1, 2*y, now);
        solve(2*y+2, b, fa);
    }
    else {
        int x = findmin(dp1, num1, a/2, (b-1)/2);
        int y = findmin(dp0, num0, x+1, b/2);
        ret.push_back({num1[x], num0[y]});
        int now = ret.size() - 1;
        if (fa != -1) {
            sons[fa].push_back(now);
            degree[now]++;
        }

        else cur.insert(now);
        solve(a, 2*x, fa);
        solve(2*x+2, 2*y-1, now);
        solve(2*y+1, b, fa);
    }
}


int main() {
//    freopen("test.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    n = N / 2;
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) scanf("%d", &num0[i/2]);
        else scanf("%d", &num1[i/2]);
    }
    make_st(dp0, num0);
    make_st(dp1, num1);
    solve(0, N-1, -1);

    while (!cur.empty()) {
        auto it = cur.begin();
        printf("%d %d ", ret[*it].first, ret[*it].second);
        int dad = *it;
        cur.erase(it);
        for (int son : sons[dad]) {
            degree[son]--;
            if (degree[son] == 0) cur.insert(son);
        }
    }
    cout << endl;
    return 0;
}