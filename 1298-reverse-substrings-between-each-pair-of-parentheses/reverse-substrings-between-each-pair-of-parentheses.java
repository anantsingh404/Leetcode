class Solution {
    public String reverseParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        StringBuilder res = new StringBuilder();
        for(int i=0;i<s.length();i++) {
            char ch = s.charAt(i);
            if(ch == '(') {
                st.push(res.length());
            }
            else if(ch == ')') {
                int start = st.pop();
                int end = res.length()-1;
                reverse(res,start,end);
            }
            else {
                res.append(ch);
            }
        }
        return res.toString();
    }
    public void reverse(StringBuilder sb,int start,int end) {
        while(start < end) {
            char temp = sb.charAt(start);
            sb.setCharAt(start,sb.charAt(end));
            sb.setCharAt(end,temp);
            start++;
            end--;
        }
    }
}