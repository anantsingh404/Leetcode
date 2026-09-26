class Solution {
    public String evaluate(String s, List<List<String>> k) {
        HashMap<String,String>mp=new HashMap<>();
        for(int i=0;i<k.size();i++)
        {
            String key=k.get(i).get(0);
             String val=k.get(i).get(1);
             mp.put(key,val);

        }
        StringBuilder st=new StringBuilder();
        int i=0;
        int n=s.length();
        
        while(i<n)
        {   
            boolean braces=false;
           
            if(s.charAt(i)=='(' )
            {
                i++;
                braces=true;
            }
            else if(s.charAt(i)==')')
            {
                i++;

            }
           
            int j=i;
            if(j>=n)
            {
                break;
            }
           
            while(j<n && s.charAt(j)>='a' && s.charAt(j)<='z')
            {
                j++;
            }
           

            String sub = s.substring(i, j); 
            System.out.println(sub);
            if(braces==true && mp.containsKey(sub))
            {   
                String x=mp.get(sub);
                st.append(x);
            }
            else if(braces==true)
            {
                st.append('?');
            }
            else
            {
           
            st.append(sub);
            }
            i=j;
        }
        return st.toString();





    }
}