#include <iostream>
#include <vector>
using namespace std;

struct TrieNode{
    vector<TrieNode*> nxt;
    int cnt = 0;
};

const int MAXN = 1e5 + 10;
bool vis[MAXN];
vector<int> nums[MAXN];
TrieNode* tries[MAXN];
int ret;


void insert(int k, int val) {
    if (tries[k] == NULL) tries[k] = new TrieNode();
    auto root = tries[k];
    for (int i = 16; i >= 0; i--) {
        root->cnt++;
        if (root->nxt.empty()) root->nxt.resize(2);
        int idx = 0;
        if (val & (1<<i)) idx = 1;
        if (root->nxt[idx] == NULL) root->nxt[idx] = new TrieNode();
        root = root->nxt[idx];
    }
}



void insert(int x) {
    if (vis[x]) return;
    vis[x] = true;
    for (int num : nums[x]) {
        insert(num, x);
    }
}

bool query(TrieNode* cur, int x, int s, int val, int i) {
    if (i == -1) {
        ret = val;
        return true;
    }
    if (cur == NULL) return false;
    int idx = 1;
    if (x & (1<<i)) idx = 0;
    if (x + val + (idx<<i) > s || cur->nxt[idx] == NULL || !query(cur->nxt[idx], x, s, val+(idx<<i), i-1)) {
        idx = 1 - idx;
        if (x + val + (idx<<i) > s || cur->nxt[idx] == NULL || !query(cur->nxt[idx], x, s, val+(idx<<i), i-1)) {
            return false;
        }
        return true;
    }
    return true;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            nums[j].push_back(i);
        }
    }
    int q; cin >> q;
    int cmd, x, k, s;
    while (q--) {
        cin >> cmd >> x;
        if (cmd == 1) insert(x);
        else {
            cin >> k >> s;
            ret = -1;
            if (x % k == 0) query(tries[k], x, s, 0, 16);
            cout << ret << '\n';

        }
    }

    return 0;
}