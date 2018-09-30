#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<LL, int> pli;
const int mod = 1e9 + 7;
const int MAXN = 3e5 + 10;
struct Info{
    int sz = 0, hash1 = 0, hash2 = 0;
    LL sum = 0;
    bool operator==(Info const & other) const {
        return other.sz == sz && other.sum == sum && other.hash1 == hash1 && other.hash2 == hash2;
    }
};
Info info1[MAXN], info2[MAXN];
vector<int> edges1[MAXN], edges2[MAXN];
map<pli, vector<int> > table;
LL n, ret = 0;

void dfs1(int cur) {
    int sz = 1;
    LL sum = cur;
    int hash1 = cur;
    int hash2 = 1LL * cur * cur * mod;
    for (int son : edges1[cur]) {
        dfs1(son);
        sz += info1[son].sz;
        sum += info1[son].sum;
        hash1 ^= info1[son].hash1;
        hash2 ^= info1[son].hash2;
    }
    table[{sum, sz}].push_back(cur);
    info1[cur].sz = sz;
    info1[cur].sum = sum;
    info1[cur].hash1 = hash1;
    info1[cur].hash2 = hash2;
}
void dfs2(int cur) {
    int sz = 1;
    LL sum = cur;
    int hash1 = cur;
    int hash2 = 1LL * cur * cur * mod;
    for (int son : edges2[cur]) {
        dfs2(son);
        sz += info2[son].sz;
        sum += info2[son].sum;
        hash1 ^= info2[son].hash1;
        hash2 ^= info2[son].hash2;
    }
    info2[cur].sz = sz;
    info2[cur].sum = sum;
    info2[cur].hash1 = hash1;
    info2[cur].hash2 = hash2;
    if (cur == 1) return;

    auto it = table.find({sum, sz});
    if (it != table.end()) {
        for (int i : it->second) {
            if (info1[i] == info2[cur]) {
                ret++;
                break;
            }
        }
    }
    else {
        Info tmp;
        tmp.sz = n - info2[cur].sz;
        tmp.sum = (n+1)*n/2 - info2[cur].sum;
        tmp.hash1 = info2[cur].hash1 ^ info1[1].hash1;
        tmp.hash2 = info2[cur].hash2 ^ info1[1].hash2;
        it = table.find({tmp.sum, tmp.sz});
        if (it != table.end()) {
            for (int i : it->second) {
                if (tmp == info1[i]) {
                    ret++;
                    break;
                }
            }
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0), cin.tie(0);
    int val;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> val;
        edges1[val].push_back(i);
    }
    for (int i = 2; i <= n; i++) {
        cin >> val;
        edges2[val].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    cout << ret << endl;

    return 0;
}