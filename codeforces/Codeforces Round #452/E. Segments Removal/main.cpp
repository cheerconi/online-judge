#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAXN = 200000 + 10;
int nums[MAXN], cnt[MAXN];
int nxt[MAXN], pre[MAXN];
bool used[MAXN];
struct cmp{
    bool operator() (pii a, pii b) {
        if (a.first != b.first) {
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};
int main() {
//    freopen("test.txt", "r", stdin);
    int n, val;
    scanf("%d", &n);
    int idx = 0;
    priority_queue<pii, vector<pii>, cmp> pq;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val);
        if (nums[idx] != val) {
            idx++;
            nums[idx] = val;
            cnt[idx] = 1;
            nxt[idx-1] = idx;
            pre[idx] = idx-1;
            if (cnt[idx-1] != 0) {
                pq.push({cnt[idx-1], idx-1});
            }
        }
        else {
            cnt[idx]++;
        }
    }
    pq.push({cnt[idx], idx});
    pre[0] = idx;
    int ret = 0;
    while (!pq.empty()) {
        pii item = pq.top();
        int a = item.second;
        pq.pop();
        if (used[a]) continue;
        used[a] = true;
        ret++;
        if (pre[a] != 0 && nxt[a] != 0 && nums[pre[a]] == nums[nxt[a]]) {
            int tmp = cnt[pre[a]] + cnt[nxt[a]];
            used[nxt[a]] = true;
            nxt[pre[a]] = nxt[nxt[a]];
            pre[nxt[nxt[a]]] = pre[a];
            pq.push({tmp, pre[a]});
            cnt[pre[a]] = tmp;
        }
        else {
            nxt[pre[a]] = nxt[a];
            pre[nxt[a]] = pre[a];
        }
    }
    cout << ret << endl;

    return 0;
}