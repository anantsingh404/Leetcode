class Solution {
    public int minPartitions(String n) {
     int maxi=0;
     for(int i=0;i<n.length();i++)
     {
        maxi=Math.max(maxi,(int)(n.charAt(i)-'0'));
     } 
     return maxi;  
    }
}