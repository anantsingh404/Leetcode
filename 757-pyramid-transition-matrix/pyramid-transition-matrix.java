class Solution {
   // Map to quickly find allowed tops: "AB" -> ['C', 'D']
    private Map<String, List<Character>> allowedPatterns = new HashMap<>();

    // Memoization to store rows that cannot reach the top
    private Set<String> memo = new HashSet<>();

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        // Preprocess allowed patterns
        for (String s : allowed) {
            String key = s.substring(0, 2);
            char value = s.charAt(2);
            allowedPatterns
                .computeIfAbsent(key, k -> new ArrayList<>())
                .add(value);
        }

        return solve(bottom);
    }

    // Layer 1: Vertical Recursion
    private boolean solve(String row) {
        // Base case
        if (row.length() == 1) {
            return true;
        }

        // Memo check
        if (memo.contains(row)) {
            return false;
        }

        // Try building the next row
        if (buildNextRow(row, new StringBuilder(), 0)) {
            return true;
        }

        // Mark as failed
        memo.add(row);
        return false;
    }

    // Layer 2: Horizontal Recursion
    private boolean buildNextRow(String currentRow, StringBuilder nextRow, int idx) {
        // Fully built next row
        if (idx == currentRow.length() - 1) {
            return solve(nextRow.toString());
        }

        String key = currentRow.substring(idx, idx + 2);

        // No valid pattern
        if (!allowedPatterns.containsKey(key)) {
            return false;
        }

        // Try all possible tops
        for (char ch : allowedPatterns.get(key)) {
            nextRow.append(ch);
            if (buildNextRow(currentRow, nextRow, idx + 1)) {
                return true;
            }
            nextRow.deleteCharAt(nextRow.length() - 1); // backtrack
        }

        return false;
    }
}