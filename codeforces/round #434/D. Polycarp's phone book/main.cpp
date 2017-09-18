#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct TrieNode {
    bool unique = true;
    vector<TrieNode*> sons;
    int id = 0;
};
TrieNode *root;
const int MAXN = 70000 + 10;
int nums[MAXN];

void add(string s, int id) {
    auto cur = root;
    for (char c : s) {
        if (cur->sons.size() == 0) {
            cur->sons = vector<TrieNode*>(10, NULL);
        }
        if (cur->sons[c-'0'] == NULL) {
            cur->sons[c-'0'] = new TrieNode();
        }
        cur = cur->sons[c-'0'];
        if (cur->id != 0 && cur->id != id) {
            cur->unique = false;
        }
        else {
            cur->id = id;
        }
    }
}
void add(int num, int id) {
    string s = to_string(num);
    for (int i = 0; i < s.size(); i++) {
        add(s.substr(i), id);
    }
}

bool find(string s) {
    auto cur = root;
    for (char c : s) {
        cur = cur->sons[c-'0'];
    }
    if (cur->unique) return true;
    return false;
}

string find(int num) {
    string s = to_string(num);
    for (int len = 1; len <= s.size(); len++) {
        for (int i = 0; i+len <= s.size(); i++) {
            if (find(s.substr(i, len))) return s.substr(i,len);
        }
    }
}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    cin >> n;
    root = new TrieNode();
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
        add(nums[i], i);
    }
    for (int i = 1; i <= n; i++) {
        cout << find(nums[i]) << endl;
    }
    return 0;
}