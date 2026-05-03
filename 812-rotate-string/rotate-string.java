class Solution {
    public boolean rotateString(String s, String goal) {
          if (s.length() != goal.length()) return false;
        
        for (int i = 0; i < s.length(); i++) {
            // Correctly rotate s by taking the suffix and adding the prefix
            String rotated = s.substring(i) + s.substring(0, i);
            if (rotated.equals(goal)) {
                return true;
            }
        }
        return false;
    }
}