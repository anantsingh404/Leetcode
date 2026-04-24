class Solution {
    public int furthestDistanceFromOrigin(String moves) {
     int left=0;
     int right=0;
     int dash=0;
     for(int i=0;i<moves.length();i++){
         char x=moves.charAt(i);
         if(x=='R')
         {
            ++right;
         }
         else if(x=='L')
         {
            ++left;
         }
         else
         {
            ++dash;
         }
     }
     return Math.max(left,right)-Math.min(left,right)+dash;   
    }
}