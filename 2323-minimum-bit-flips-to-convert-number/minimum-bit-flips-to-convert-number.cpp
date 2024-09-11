class Solution {
public:
    int minBitFlips(int start, int goal) {
        int i=0;
        int count=0;
        while(i<32)
        {
            if((start&(1<<i))!=(goal&(1<<i)))
            {
                ++count;
            }
            i++;
        }
        return count;
    }
};