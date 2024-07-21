class Solution {
public:
    int minChanges(int n, int k) {
     int count=0;
     int i=0;
     while(i<32) 
     {
        if(((1<<i)&n)==((1<<i)&k))
        {   i++;
        }
        else if(((1<<i)&n) && !((1<<i)&k))
        {
            ++count;
            i++;

        }
        else 
        {
            return -1;
        }
     }  
     return count;
    }
};