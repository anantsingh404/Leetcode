class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int re=red;
        int bl=blue;
        int rc=2;
       int  bc=1;
        int count=0;
        int turn=0;
       
        while(red || blue)
        {
            if(blue>=bc && turn==0)
            {
                blue-=bc;
                bc+=2;
                ++count;
                turn=1;
            }
            if(red>=rc && turn==1)
            {
                red-=rc;
                rc+=2;
                ++count;
                turn =0;
            }
            if((red<rc &&  turn==1) || (blue<bc && turn==0))
            {
                break;
            }
            
        }
       int count1=0;
        rc=1;
       bc=2;
        //int count=0;
        turn=0;
        red=re;
        blue=bl;
       
        while(red || blue)
        {
            if(blue>=bc && turn==1)
            {
                blue-=bc;
                bc+=2;
                ++count1;
                turn=0;
            }
            if(red>=rc && turn==0)
            {
                red-=rc;
                rc+=2;
                ++count1;
                turn =1;
            }
            if((red<rc &&  turn==0) || (blue<bc && turn==1))
            {
                break;
            }
            
        }
       
        return max(count,count1);
        
    }
};