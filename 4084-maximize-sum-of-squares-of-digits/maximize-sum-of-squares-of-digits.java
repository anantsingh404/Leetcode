class Solution {
    public String maxSumOfSquares(int n, int sum) {
        StringBuilder str=new StringBuilder();
        while(sum>=0 && n>0)
        {
            int x=0;
            if(sum>=9)
            {
                x=9;
                sum-=9;
            }
            else 
            {
                x=sum;
                sum=0;
            }
            String y=Integer.toString(x);
            str.append(y);
            --n;
        }
        if(sum>0)
        {
            return "";
        }
        return str.toString();
    }
}