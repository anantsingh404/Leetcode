class Solution {
    public int minAddToMakeValid(String s) {
     int count=0;
     int n=s.length();
     int open=0;
     
     for(int i=0;i<n;i++)
     {  char x=s.charAt(i);
        if(x=='('){
            ++open;
        }
        else if(x==')' && open>0){
            --open;
        }
        else
        {
            ++count;
        }
     } 
     return count+open;  
    }
}