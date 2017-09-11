#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
struct TrieNode{
    bool end = false;
    vector<TrieNode*> sons;
    int dp0 = 0;
    int dp1 = 0;
    ~TrieNode() {
        if (!sons.empty()) {
            for (int i = 0; i < 26; i++) {
                delete sons[i];
            }
        }
    }
};

void add (TrieNode* root, string & s, int end, bool reverse = false) {
    TrieNode* cur = root;
    int delta = 1;
    int start = 0;
    int n = end;
    if (reverse) {
        delta = -1;
        start = n - 1;
    }
    for (int i = start; i >= 0 && i < n; i += delta) {
        char c = s[i];
        if (cur->sons.empty()) cur->sons = vector<TrieNode*>(26, NULL);
        if (cur->sons[c-'a']==NULL) cur->sons[c-'a'] = new TrieNode();
        cur = cur->sons[c-'a'];
    }
    cur->end = true;
}
void dfs2(TrieNode *root) {
    if (root->sons.empty()) {
        if (root->end) root->dp1 = 1;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (root->sons[i] == NULL) continue;
        dfs2(root->sons[i]);
        root->dp0 += max(root->sons[i]->dp1, root->sons[i]->dp0);
        if (root->end) root->dp1 += root->sons[i]->dp0;
    }
    if (root->end) root->dp1++;
}
void print(TrieNode * root) {
    cout << root->dp0 << ' ' << root->dp1 << endl;
    if (root->sons.empty()) return;
    for (int i = 0; i < 26; i++) {
        if (root->sons[i] == NULL) continue;
        printf("%c ", 'a'+i);
        print(root->sons[i]);
    }
}

int main() {
    freopen("test.txt", "r", stdin);
    int t, n;
    string s;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        TrieNode *root2 = new TrieNode();
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int i = 1; i <= s.size(); i++) {
                add(root2, s, i, true);
            }
        }
        dfs2(root2);
        printf("%d\n", max(root2->dp1, root2->dp0));
//        print(root2);
        delete root2;
    }
    return 0;
}