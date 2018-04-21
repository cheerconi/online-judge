#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <cctype>
using namespace std;
const int MAXN = 3e5 + 10;
int ret[MAXN], best[MAXN];
vector<int> edges[MAXN], rev[MAXN];
unordered_map<string, int> table;
int tag[MAXN], state[MAXN], tot, scc[MAXN], a[MAXN], b[MAXN], degree[MAXN], len[MAXN], cnt[MAXN];
bool vis[MAXN];

bool is_better_than(int i, int j) {
    if (cnt[i] != cnt[j]) return cnt[i] < cnt[j];
    return len[i] < len[j];
}

void make_tag(int cur) {
    if (vis[cur]) return;
    vis[cur] = true;
    for (int nxt : edges[cur]) {
        make_tag(nxt);
    }
    tag[tot++] = cur;
}
void make_scc(int cur, int root) {
    if (scc[cur] != -1) return;
    scc[cur] = root;
    if (is_better_than(best[cur], best[tag[root]])) {
        best[tag[root]] = best[cur];
    }
    for (int nxt : rev[cur]) {
        make_scc(nxt, root);
    }
}

void dfs(int cur) {
    state[cur] = 1;
    for (int nxt : edges[cur]) {
        if (state[nxt] == 0) dfs(nxt);
        if (is_better_than(best[tag[nxt]], best[tag[cur]])) {
            best[tag[cur]] = best[tag[nxt]];
        }
    }
    state[cur] = -1;
}


int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        transform(s.begin(), s.end(), s.begin(),::tolower);

        if (table.find(s) == table.end()) {
            table[s] = tot++;
            best[tot-1] = ret[i];
            int tmp1 = 0, tmp2 = 0;
            for (char c : s) {
                if (c == 'r') tmp1++;
                tmp2++;
            }
            cnt[tot-1] = tmp1;
            len[tot-1] = tmp2;
            best[tot-1] = tot-1;
        }
        ret[i] = table[s];

    }
    int m; cin >> m;
    string s1, s2;
    for (int i = 0; i < m; i++) {
        cin >> s1 >> s2;
        transform(s1.begin(), s1.end(), s1.begin(),::tolower);
        transform(s2.begin(), s2.end(), s2.begin(),::tolower);
        if (table.find(s1) == table.end()) {
            table[s1] = tot++;
            best[tot-1] = tot-1;
            int tmp1 = 0, tmp2 = 0;
            for (char c : s1) {
                if (c == 'r') tmp1++;
                tmp2++;
            }
            cnt[tot-1] = tmp1;
            len[tot-1] = tmp2;
        }
        if (table.find(s2) == table.end()) {
            table[s2] = tot++;
            best[tot-1] = tot-1;
            int tmp1 = 0, tmp2 = 0;
            for (char c : s2) {
                if (c == 'r') tmp1++;
                tmp2++;
            }
            cnt[tot-1] = tmp1;
            len[tot-1] = tmp2;
        }
        a[i] = table[s1];
        b[i] = table[s2];
        edges[a[i]].push_back(b[i]);
        rev[b[i]].push_back(a[i]);
    }
    memset(scc, -1, sizeof(scc));
    tot = 0;
    for (int i = 0; i < table.size(); i++) {
        make_tag(i);
    }
    for (int i  = (int)table.size()-1; i >= 0; i--) {
        if (scc[tag[i]] == -1) make_scc(tag[i], i);
    }
    for (int i = 0; i < table.size(); i++) edges[i].clear();
    for (int i = 0; i < m; i++) {
        if (scc[a[i]] == scc[b[i]]) continue;
        edges[scc[a[i]]].push_back(scc[b[i]]);
    }
    for (int i = 0; i < table.size(); i++) {
        sort(edges[i].begin(), edges[i].end());
        edges[i].resize(unique(edges[i].begin(), edges[i].end()) - edges[i].begin());
        for (int j : edges[i]) degree[j]++;
    }
    for (int i = 0; i < table.size(); i++) {
        if (degree[scc[i]] != 0) continue;
        if (state[scc[i]] == 0) dfs(scc[i]);
    }
    long long cnt_ret = 0, len_ret = 0;
    for (int i = 0; i < n; i++) {
        int j = tag[scc[ret[i]]];
        cnt_ret += cnt[best[j]];
        len_ret += len[best[j]];
    }
    cout << cnt_ret << ' ' << len_ret << endl;
    return 0;
}