#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 5000 + 10;
int nums[MAXN];
int other[MAXN];
int n;

int find(int left, int right, LL target) {
    while (left < right-1) {
        int mid = (left + right) >> 1;
        if (other[mid] >= target) right = mid-1;
        else left = mid;
    }
    if (right >= 0 && other[right] < target) return right;
    if (other[left] < target) return left;

    else return -1;
}

LL solve(int waist) {
    int k = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == waist) {
            cnt++;
            continue;
        }
        other[k++] = nums[i];
    }
    LL ret = 0;
    for (int i = 0; i < k; i++) {
        int pos = find(i+1, k-1, 2LL*waist+other[i]);
        int j = i+1;
        while (j < k && other[j]==other[i]) j++;
        if (pos >= j && pos < k) {
            ret += pos - j + 1;
        }
    }
    ret =  ret * cnt * (cnt-1) / 2;
    LL ret2 = 0;
    if (cnt >= 3) {
        for (int i = 0; i < k; i++) {
            if (abs(other[i]-waist) < 2*waist) ret2++;
        }
        ret2 = ret2 * cnt * (cnt-1) * (cnt-2) / 6;
    }
    return ret+ret2;

}


int main() {
    freopen("test.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
        sort(nums, nums+n);
        LL cnt = 0;
        int pre = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i-1] && nums[i]!=pre) {
                cnt += solve(nums[i]);
                pre = nums[i];
            }
        }
        printf("Case #%d: %lld\n", t, cnt);
    }
}