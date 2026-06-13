class Solution {
    public String mapWordWeights(String[] words, int[] weights) {
     StringBuilder str=new StringBuilder();
    // HashMap<Integer,Integer>mp=new HashMap<>();
     
     for(int i=0;i<words.length;i++)
     {
        int sum=0;
        String x=words[i];
        for(int j=0;j<x.length();j++)
        {
            int p=x.charAt(j)-'a';
            sum+=weights[p];
        }
       
        char xx=(char)('z'-sum%26);
        str.append(xx); 

     }
     return str.toString();

    }
}