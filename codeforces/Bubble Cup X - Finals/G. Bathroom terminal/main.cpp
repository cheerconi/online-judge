#include <iostream>
#include <string>
#include <map>
using namespace std;
const int MAXN = 100000 + 10;
struct TrieNode{
    int num = 0;
    map<int, TrieNode*> next;
    int id = -1;
};
int cnt;
string pattern;

void find(TrieNode* root, int i, int now) {
    if (i == pattern.size() && root->id < now) {
        cnt += root->num;
        root->id = now;
        return;
    }
    if (pattern[i] == '?') {
        for (auto it = root->next.begin(); it != root->next.end(); it++) {
            find(it->second, i+1, now);
        }
        find(root, i+1, now);
    }
    else {
        if (root->next.find(pattern[i]-'a') != root->next.end()) {
            find(root->next[pattern[i]-'a'], i+1, now);
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    string s;
    int n, m;
    TrieNode* root = new TrieNode();
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        cin >> s;
        TrieNode * now = root;
        for (char c : s) {
            if (now->next[c-'a'] == NULL) {
                TrieNode *tmp = new TrieNode();
                now->next[c-'a'] = tmp;
            }
            now = now->next[c-'a'];
        }
        now->num++;
    }
    for (int i = 0; i < m; i++) {
        cnt = 0;
        cin >> pattern;
        find(root, 0, i);
        printf("%d\n", cnt);
    }
    return 0;
}