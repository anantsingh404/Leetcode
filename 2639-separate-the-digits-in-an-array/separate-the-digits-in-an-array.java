class Solution {
    public int[] separateDigits(int[] nums) {
        ArrayList<Integer>ls=new ArrayList<>();
        int n=nums.length;
        for(int i=0;i<n;i++)
        {
            int x=nums[i];
            ArrayList<Integer>l=new ArrayList<>();
            while(x>0)
            {
                l.add(x%10);
                x/=10;
            }
            Collections.reverse(l);
            int m=l.size();
            for(int j=0;j<m;j++)
            {
                ls.add(l.get(j));
            }
        }
        int m=ls.size();
        int ans[]=new int[m];
        for(int i=0;i<m;i++)
        {
            ans[i]=ls.get(i);
        }
        return ans;

    }
}