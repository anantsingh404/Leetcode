class Solution {
    void solve(int open, int close, int n, StringBuilder temp, List<String> ls) {
        // Base case: If we have used all n open and n close brackets, it's valid
        if (temp.length() == 2 * n) {
            ls.add(temp.toString());
            return;
        }

        // Optimization: Only add '(' if we haven't reached the limit 'n'
        if (open < n) {
            temp.append('(');
            solve(open + 1, close, n, temp, ls);
            temp.deleteCharAt(temp.length() - 1); // Backtrack
        }

        // Optimization: Only add ')' if it physically matches a preceding '('
        if (close < open) {
            temp.append(')');
            solve(open, close + 1, n, temp, ls);
            temp.deleteCharAt(temp.length() - 1); // Backtrack
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> ls = new ArrayList<>();
        StringBuilder temp = new StringBuilder();
        // Start with 0 open and 0 close brackets placed
        solve(0, 0, n, temp, ls);  
        return ls;
    }
}
