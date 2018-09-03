#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int kmp(string &pa, string &s) {
    int n = pa.size();
    vector<int> next(n+1, 0);
    next[0] = -1;
    for (int i = 2; i <= n; i++) {
        int pre = next[i-1];
        while (pre!=-1 && pa[pre]!=pa[i-1]) pre = next[pre];
        next[i] = pre + 1;
    }
    int i = 0, j = 0, cnt = 0;
    while (i < s.size()) {
        while (i < s.size() && j < n && s[i] == pa[j]) i++, j++;
        if (j == n) cnt++;
        if (j != 0) j = next[j];
        else i++;
    }
    return cnt;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while (n--) {
        string pa, s;
        cin >> pa >> s;
        cout << kmp(pa, s) << endl;

    }
    return 0;
}