class Solution {
public:
    int passThePillow(int n, int time) {
       int x=time/(n-1);
       if(x%2)
       {
        return n-time%(n-1);
       } 
       
        return time%(n-1)+1;
       
    }
};