#include <iostream>
#include <queue>
typedef long long LL;
using namespace std;
int main() {
    int n, val;
    cin >> n;
    priority_queue<LL> pq;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        pq.push((LL)val);
    }
    LL ret = 0;
    while (pq.size() >= 2) {
        LL a = pq.top();
        pq.pop();
        LL b = pq.top();
        pq.pop();
        ret += a + b;
        pq.push(a+b);
    }
    cout << ret << endl;
    return 0;
}