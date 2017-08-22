#include <iostream>
#include <limits.h>
#include <stack>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int speed = 0;
    int take = 0;
    int ban = -1;
    int id, para;
    int cnt = 0;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &id);
        if (id == 1) {
            scanf("%d", &para);
            speed = para;
            if (ban != -1 && ban < speed) {
                while (!s.empty() && s.top()<speed) {
                    s.pop();
                    cnt++;
                }
            }
        }
        if (id == 2) {
            if (take > 0)  {
                cnt += take;
                take = 0;
            }
        }
        if (id == 3) {
            scanf("%d", &para);
            if (para < speed) cnt++;
            else {
                s.push(para);
                ban = para;
            }
        }
        if (id == 4) {
            take = 0;
        }
        if (id == 5) {
            while(!s.empty()) s.pop();
        }
        if (id == 6) take++;
    }
    cout << cnt << endl;

    return 0;
}