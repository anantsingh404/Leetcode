class Solution {
public:
    int minimizeXor(int num1, int num2) {
     int count= __builtin_popcount(num2);  
     int x=0;
     for(int i=31;i>=0;i--)
     {
        if(((1<<i)&num1) && count)
        {   x=(x|(1<<i));
            --count;
        }
     }
     for(int i=0;i<32;i++)
     {
        if(count==0)
        {
            break;
        }
        if(((1<<i)&num1)==0 && count)
        {
            x= (x|(1<<i));
            --count;
        }
     }
     return x;

    }
};