#include <iostream>
#include <random>
#include <memory.h>
using namespace std;
const int MAXN = 50000 + 10;
int nums[MAXN], net[MAXN];
int n, start, target, pos = -1;

bool ask(int i) {
    if (nums[i] >= 0) return false;
    int a, b;
    cout << "? " << i << endl;
    scanf("%d%d", &a, &b);
    if (a == target) {
        cout << "! " << target << endl;
        exit(0);
    }
    nums[i] = a;
    net[i] = b;
    if (nums[i] < target) {
        if (pos==-1 || nums[i] > nums[pos]) pos = i;
    }
    return true;
}


int main() {
    memset(nums, -1, sizeof(nums));
    scanf("%d%d%d", &n, &start, &target);
    ask(start);
    if (nums[start] > target) {
        cout << "! " << nums[start] << endl;
        return 0;
    }
    default_random_engine generator(9397);
    uniform_int_distribution<int> distribution(1, n);
    int cnt = 1;
    for (int i = 1; i < 3000; i++) {
        int num = distribution(generator);
        if (ask(num)) cnt++;
        if (cnt == 1000) break;

    }
    for (int i = 1001; i < 1999; i++) {
        pos = net[pos];
        if (pos == -1) break;
        ask(pos);
        if (nums[pos] > target) {
            cout << "! " << nums[pos] << endl;
            return 0;
        }
    }
    cout << "! -1" << endl;
    return 0;
}