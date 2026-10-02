class Solution {
    // Replaced heavy Stack object with a fast primitive integer counter
    boolean Check(StringBuilder s) {
        int balance = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            char x = s.charAt(i);
            if (x == '(') {
                balance++;
            } else {
                balance--;
            }
            // If balance goes negative, a closing bracket appeared without an opening one
            if (balance < 0) return false; 
        }
        return balance == 0;
    }

    void solve(int n, StringBuilder temp, List<String> ls) {
        if (n == 0) {
            if (Check(temp)) {
                ls.add(temp.toString());
            }
            return;
        }
        
        // Minor tweak: Flipped order to append '(' first, as valid strings must start with '('
        temp.append('(');
        solve(n - 1, temp, ls);
        temp.deleteCharAt(temp.length() - 1);

        temp.append(')');
        solve(n - 1, temp, ls);
        temp.deleteCharAt(temp.length() - 1);
    }

    public List<String> generateParenthesis(int n) {
        List<String> ls = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        solve(2 * n, temp, ls);  
        return ls;
    }
}
