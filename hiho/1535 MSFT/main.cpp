#include <iostream>
#include <vector>
#include <string>
#include <limits.h>
using namespace std;
int ret;
void dfs(string & a, string & b, int & now, int i, vector<bool>  & used){
    if (used.size() <= 1) {
        ret = min(ret, now);
        return;
    }
    if (used[i]) {
        string a_tmp, b_tmp;
        int tmp = 0;
        for (int j = 0; j < used.size(); j++) {
            if (!used[j]) {
                a_tmp.push_back(a[j]);
                b_tmp.push_back(b[j]);
                tmp++;
            }
        }
        now += (a.size() - tmp - 1);
        vector<bool> used_tmp(a_tmp.size(), false);
        dfs(a_tmp, b_tmp, now, 0, used_tmp);
        return;
    }
    used[i] = true;
    char ac = a[i];
    for (int j = 0; j < b.size(); j++) {
        if (b[j] == ac) {
            int tmp_now = now;
            dfs(a, b, tmp_now, j, used);
        }
    }
    used[i] = false;
    return;

}

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    while(n--) {
        ret = INT_MAX;
        string a, b;
        cin >> a >> b;
        int now = 0;
        vector<bool> used(a.size(), false);
        used[0] = true;
        for (int i = 0; i < b.size(); i++) {
            if (b[i] == a[0]) {
                int now = 0;
                dfs(a, b, now, i, used);
            }
        }
        cout << ret << endl;


    }
}