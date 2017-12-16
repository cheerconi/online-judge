#include <iostream>
#include <string>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 10;
struct TrieNode{
    bool end = false;
    LL deep = 0;
    TrieNode * nxt[2];
    TrieNode(int _deep) {
        deep = _deep;
        nxt[0] = nxt[1] = NULL;
    }
};
int n;
LL l, ret;

void add (TrieNode* root, string &s) {
    for (char c : s) {
        int p = c - '0';
        if (root->nxt[p] == NULL) root->nxt[p] = new TrieNode(root->deep+1);
        root = root->nxt[p];
    }
    root->end = true;
}
void solve(TrieNode *root) {
    if (root == NULL) return;
    if (root->deep == l) return;
    int cnt = 0;
    cnt += (root->nxt[0] != NULL);
    cnt += (root->nxt[1] != NULL);
    if (cnt == 0) return;
    if (cnt == 1) {
        LL val = l - root->deep;
        LL tmp = 1;
        while ((val&1) == 0) {
            val >>= 1;
            tmp <<= 1;
        }
        ret ^= tmp;
    }
    solve(root->nxt[0]);
    solve(root->nxt[1]);
}
int main() {
//    freopen("test.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    TrieNode *root = new TrieNode(0);
    cin >> n >> l;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        add (root, s);
    }
    solve(root);
    if (ret > 0) cout << "Alice" << endl;
    else cout << "Bob" << endl;
    return 0;
}