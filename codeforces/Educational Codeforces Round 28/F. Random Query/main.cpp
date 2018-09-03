#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
//    freopen("test.txt", "r", stdin);
    int n, num;
    scanf("%d", &n);
    unordered_map<int, int> table;
    double ret = 1;
    double now = 1;
    scanf("%d", &num);
    table[num] = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d", &num);
        auto it = table.find(num);
        if(it == table.end()) {
            now = (now+1) + 2LL*i + 1;
        }
        else {
            now = (now+1) + 1 + 2LL*(i - it->second - 1);
        }
        ret  = ret + now;
        table[num] = i;
    }
    ret = ret / ((double)n*n);
    printf("%.10f\n", ret);
    return 0;
}