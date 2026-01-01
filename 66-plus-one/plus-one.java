class Solution {
    public int[] plusOne(int[] d) 
    {
        
        
        Integer carry=1;
        for(int i=d.length-1;i>=0;i--)
        {
            carry=carry+d[i];
            d[i]=carry%10;
            carry/=10;
        }
        if(carry==0)
        {
            return d;
        }
        else
        {
            int []arr=new int[d.length+1];
            for(int i=d.length-1;i>0;i--)
        {
            
            arr[i]=d[i];
            
        }
        arr[0]=carry;
        return arr;
        }
    
       




    }
}