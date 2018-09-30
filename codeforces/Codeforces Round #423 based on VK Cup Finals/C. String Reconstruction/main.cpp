#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
static const int MAXN = 2000000 + 5000;

int main() {
//    freopen("test.txt", "r", stdin);
    int n, k, x;
    scanf("%d", &n);
    vector<string> strs;
    char str[MAXN];
    int last = -1;
    vector<int> pos(MAXN, -1);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        string tmp(str);
        strs.push_back(tmp);
        scanf("%d", &k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &x);
            if (pos[x-1] != -1) {
                if (strs[pos[x-1]].size() > strs[i].size()) continue;
            }
            pos[x-1] = i;
            last = max(last, x-1);
        }


    }
    int i = 0;
    while (i < MAXN - 1) {
        if (pos[i] == -1 && i > last) break;
        if (pos[i] == -1) {
            printf("a");
            i++;
        }
        else {
            int tmp = pos[i];
            printf("%c", strs[tmp][0]);
            i++;
            for (int j = 1; j < strs[tmp].size(); j++,i++) {
                if (pos[i] != -1) {
                    if (strs[pos[i]].size() > strs[tmp].size() - j) break;
                }
                printf("%c", strs[tmp][j]);
            }
        }
    }
    cout << endl;

    return 0;
}