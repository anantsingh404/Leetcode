class Solution {
    public int binaryGap(int n) {
        int temp=-1;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            if(((1<<i)&n)>=1)
            {   if(temp!=-1){
                ans=Math.max(ans,temp-i);
            }
            temp=i;
            }
        }return ans;

        
    }
}