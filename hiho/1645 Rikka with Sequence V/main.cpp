#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n;
    cin >> n;
    deque<int> dq;
    if (n % 2 == 1) {
        dq.push_back(n);
        n--;
    }
    for (int i = n; i >= 1; i -= 2) {
        dq.push_back(i);
        dq.push_front(i-1);
    }
    while (!dq.empty()) {
        printf("%d", dq.front());
        dq.pop_front();
        if (dq.empty()) printf("\n");
        else printf(" ");
    }
    return 0;
}