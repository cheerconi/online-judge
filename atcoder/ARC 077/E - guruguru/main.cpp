#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
//    freopen("test.txt", "r", stdin);
    int n,m, pre, now;
    scanf("%d%d", &n, &m);
    vector<int> save(m+1, 0);
    scanf("%d", &pre);
    pre = pre % m;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &now);
        now = now % m;
        if (now < pre) now += m;
        int dis = now - pre;
        cnt += dis;
        if (pre+2 <= now) {
            if (now < m) {
                save[pre+2] += 1;
                save[now+1] -= 1;
            }
            else if (pre+2 >= m) {
                save[pre+2-m] += 1;
                save[now+1-m] -= 1;
            }
            else {
                save[pre+2] += 1;
                save[m] -= 1;
                save[0] += 1;
                save[now+1-m] -= 1;
            }
        }
        pre = now % m;
    }
    m = 0;
    for (int i = 0; i < m; i++) save[]
    cout << cnt - m << endl;
}