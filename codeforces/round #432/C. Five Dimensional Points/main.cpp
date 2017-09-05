#include <iostream>
#include <vector>
using namespace std;
const int MAXN = 1000 + 10;
int num[MAXN][5];

inline bool check(int a, int b, int c) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        cnt += (num[a][i]-num[b][i]) * (num[a][i]-num[c][i]);
    }
    if (cnt > 0) return false;
    return true;
}

int main() {
//    freopen("test.txt","r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d", &num[i][0],&num[i][1],&num[i][2],&num[i][3],&num[i][4]);
    }
    vector<int> ret;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int a = 0; a < n; a++) {
            if (a == i) continue;
            for (int b = a+1; b < n; b++) {
                if (b == i) continue;
                if (!check(i, a, b)) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) ret.push_back(i);
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i]+1;
        if (i != ret.size()-1) cout << " ";
        else cout << endl;
    }
    return 0;
}