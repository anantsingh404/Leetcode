class Solution {
public:
    int findComplement(int x) {
         unsigned int num=x;
       unsigned int i=0;
       while((1<<i)<=num)
       {
        if((1<<i)&num)
        {
            num-=(1<<i);
        }
        else
        {
            num+=(1<<i);
        }
        i++;
       } 
       return num;
    }
};