#include <iostream>
#include <bitset>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 2048;

int stob(string & s) {
    int ret = 0;
    for (char c : s) {
        ret = ret*2 + c - '0';
    }
    return ret;
}

struct Stick {
    string left, right;
    bitset<MAXN> b;

    void add (string s) {
        string pre(1, '1');
        int n = s.size();
        for (int len = 1; len <= min(n, 9); len++) {
            for (int i = 0; i+len <= n; i++) {
                string cur = pre + s.substr(i, len);
                b[stob(cur)] = true;
            }
        }
    }
    void prune() {
        if (left.size() > 8) {
            left = left.substr(0, 8);
            int n = right.size();
            right = right.substr(n-8, 8);
        }
    }
    void init (string & s) {
        this->add(s);
        left = s;
        right = s;
        prune();
    }
    void add (Stick & item1, Stick & item2) {
        b = item1.b | item2.b;
        add(item1.right+item2.left);
        left = item1.left + item2.left;
        right = item1.right + item2.right;
        prune();
    }
    int solve () {
        for (int i = 9; i >= 1; i--) {
            int bias = 1 << i;
            bool flag = true;
            for (int j = 0; j < bias; j++) {
                if (b[j+bias] == false) {
                    flag = false;
                    break;
                }
            }
            if (flag) return i;
        }
        return 0;
    }
};

Stick data[210];
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    scanf("%d", &n);
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        data[i].init(s);
    }
    scanf("%d", &m);
    int a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &a, &b);
        data[i+n].add(data[a], data[b]);
        printf("%d\n", data[i+n].solve());
    }

    return 0;
}