class Solution {
    public int minMirrorPairDistance(int[] nums) {
        int n=nums.length;
        int arr[]=new int[n];
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            int y=0;
            while(x>0)
            {
                y=y*10+x%10;;
                x/=10;
            }
            arr[i]=y;
        }
        int ans=1000000;
        HashMap<Integer,Integer>mp=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            if(mp.getOrDefault(nums[i],0)>0)
            {
                ans=Math.min(i-mp.getOrDefault(nums[i],0)+1,ans);
            }
            mp.put(arr[i],i+1);
        }
        if(ans==1e6)
        {
            return -1;
        }
        return ans;
    }
}