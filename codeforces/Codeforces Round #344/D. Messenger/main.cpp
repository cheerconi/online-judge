#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
typedef pair<char, LL> pci;
vector<pci> s, pa;

bool m1(int i, int j) {
    if (i != 0) return pa[i]==pa[j];
    if (pa[i].first != pa[j].first) return false;
    return pa[i].second <= pa[j].second;
}

bool m2(int i, int j) {
    if (j != 0 && j != pa.size()-1) return s[i]==pa[j];
    if (s[i].first != pa[j].first) return false;
    return s[i].second >= pa[j].second;
}
LL kmp() {
    if (pa.size() > s.size()) return 0;
    int n = pa.size();
    vector<int> nxt(n+1, 0);
    nxt[0] = -1;
    for (int i = 2; i <= n; i++) {
        int pre = nxt[i-1];
        while (pre != -1 && !m1(pre, i-1)) pre = nxt[pre];
        nxt[i] = pre + 1;
    }
    int i = 0, j = 0;
    LL ret = 0;
    while (i < s.size()) {
        while (i < s.size() && j < n && m2(i,j)) i++, j++;
        if (j == n) {
            ret++;
            j = nxt[j];
            while (j > 1 && pa[j-1] != s[i-1]) {
                j= nxt[j];
            }
            continue;
        }
        if (j == 0) i++;
        else j = nxt[j];
    }
    return ret;
}
int main() {
//    freopen("test.txt", "r", stdin);
    int n, m;
    char c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        getchar();
        LL val = 0;
        while (true) {
            scanf("%c", &c);
            if (isdigit(c)) val = val * 10 + c - '0';
            else break;
        }
        scanf("%c", &c);
        if (i == 0 || s.back().first != c) {
            s.push_back({c, val});
        }
        else {
            s.back().second += val;
        }
    }
    for (int i = 0; i < m; i++) {
        getchar();
        LL val = 0;
        while (true) {
            scanf("%c", &c);
            if (isdigit(c)) val = val * 10 + c - '0';
            else break;
        }
        scanf("%c", &c);
        if (i == 0 || pa.back().first != c) {
            pa.push_back({c, val});
        }
        else {
            pa.back().second += val;
        }
    }
    LL ret = 0;
    if (pa.size() == 1) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i].first == pa[0].first && s[i].second >= pa[0].second) {
                ret += s[i].second - pa[0].second + 1;
            }
        }
        cout << ret << endl;
        return 0;
    }
    ret = kmp();
    cout << ret << endl;
    return 0;
}