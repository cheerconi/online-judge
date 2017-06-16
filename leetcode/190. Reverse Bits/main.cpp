#include <iostream>


uint32_t reverseBits(uint32_t n) {
    int ret = 0;
    for (int i = 0; i < 32; i++) {
        int bit = n & (1 << i);
        if (bit != 0) {
            ret += (1 <<(31-i));
        }
    }
    return ret;

}
int main() {
    std::cout << reverseBits(2) << std::endl;
    return 0;
}