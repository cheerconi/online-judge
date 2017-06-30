#include <iostream>
#include <stack>
#include <set>
#include <queue>
using namespace std;

int main() {
//    freopen("test.txt", "r", stdin);
    int N, id;
    char cmd[10];
    scanf("%d", &N);
    stack<int> s;
    int cnt = 0;
    int need = 1;
    for (int n = 1; n <= (N*2); n++) {
        scanf("%s" ,cmd);
        if (cmd[0] == 'a') {
            scanf("%d", &id);
            s.push(id);
        }
        else { // cmd == "remove"
            if (s.size() > 0 && s.top() == need) {
                s.pop();
            }

            else if (s.size() > 0){
                cnt++;
                while (s.size()>0) {
                    s.pop();
                }
            }
            need++;
        }
    }
    cout << cnt << endl;
    return 0;
}