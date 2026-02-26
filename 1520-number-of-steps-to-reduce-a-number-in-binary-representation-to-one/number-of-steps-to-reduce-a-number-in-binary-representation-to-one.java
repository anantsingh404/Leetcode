class Solution {
    public int numSteps(String ss) {
         int count = 0;
        StringBuilder s = new StringBuilder(ss);

        while (!s.toString().equals("1")) {

            int n = s.length();

            if (s.charAt(n - 1) == '1') {
                // add 1
                int j = n - 1;

                while (j >= 0 && s.charAt(j) == '1') {
                    s.setCharAt(j, '0');
                    j--;
                }

                if (j < 0) {
                    s.insert(0, '1');
                } else {
                    s.setCharAt(j, '1');
                }

            } else {
                // divide by 2 (right shift)
                s.deleteCharAt(n - 1);
            }

            count++;
        }
        return count;
    }
}