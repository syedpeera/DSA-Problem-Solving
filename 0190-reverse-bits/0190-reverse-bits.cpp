class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i=0;i<32;i++){
            int lsb = (n & 1);
            int reverseLsb = lsb << (31 - i);
            result = result | reverseLsb;
            n = n >> 1;
        }
        return result;
    }
};