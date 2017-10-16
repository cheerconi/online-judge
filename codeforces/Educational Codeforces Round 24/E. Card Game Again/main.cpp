#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
vector<int> primes;
struct Gene{
    vector<int> nums;
    Gene(int num) {
        for (int prime : primes) {
            int cnt = 0;
            while (num % prime == 0) {
                cnt++;
                num = num / prime;
            }
            nums.push_back(cnt);
        }
    }
    Gene (int n, int val) {
        nums = vector<int>(n, val);
    }
    Gene(vector<int> tmp) {
        nums = tmp;
    }
    void add (Gene const & g) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] += g.nums[i];
        }
    }
    void del (Gene const & g) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] -= g.nums[i];
        }
    }
    bool fulfill(Gene const & g) const {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < g.nums[i]) return false;
        }
        return true;
    }
};
int main() {
//    freopen("test.txt", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    LL cnt = 0;
    if (k == 1) {
        cnt = ((LL)n*(n+1)) >> 1;
        cout << cnt << endl;
        return 0;
    }

    // compute primes
    vector<int> nums;
    cnt = 0;
    while ((k & 1) == 0) {
        cnt++;
        k = k >> 1;
    }
    if (cnt != 0) {
        primes.push_back(2);
        nums.push_back(cnt);
    }
    for (int i = 3; k != 1; i += 2) {
        cnt = 0;
        while (k % i == 0) {
            cnt++;
            k = k / i;
        }
        if (cnt != 0) {
            primes.push_back(i);
            nums.push_back(cnt);
        }
    }

    Gene goal = Gene(nums);


    // get seq
    vector<Gene> seq;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        seq.push_back(Gene(tmp));
    }

    cnt = 0;
    int i = 0;
    int j = 0;
    Gene now = Gene(primes.size(), 0);
    while (i < n) {
        while (j < n && !now.fulfill(goal)) {
            now.add(seq[j]);
            j++;
        }
        if (now.fulfill(goal)) {
            cnt += n - j + 1;
            now.del(seq[i]);
            i++;
        }
        else break;
    }
    cout << cnt << endl;

    return 0;
}