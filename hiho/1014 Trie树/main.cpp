#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    vector<int> next;
    int cnt = 0;
};
vector<TrieNode> trie(1, TrieNode());
int size = 1;
string s;

void insert() {
    int now = 0;
    for (char c : s) {
        if (trie[now].next.size() == 0) {
            trie[now].next = vector<int>(26, -1);
        }
        if (trie[now].next[c-'a'] == -1) {
            trie[now].next[c-'a'] = size;
            trie.push_back(TrieNode());
            size++;
        }
        now = trie[now].next[c-'a'];
        trie[now].cnt++;
    }
}
int find() {
    int now = 0;
    for (char c : s) {
        if (trie[now].next.empty() || trie[now].next[c-'a']==-1) {
            return 0;
        }
        now = trie[now].next[c-'a'];
    }
    return trie[now].cnt;
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        cin >> s;
        insert();
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        cin >> s;
        printf("%d\n", find());
    }
    return 0;
}