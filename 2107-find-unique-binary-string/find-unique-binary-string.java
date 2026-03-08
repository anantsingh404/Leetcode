class Solution {
    String ans = "";

    void solve(int n, HashMap<String, Integer> mp, StringBuilder temp) {

        if (temp.length() == n) {
            String s = temp.toString();
            if (!mp.containsKey(s)) {
                ans = s;
            }
            return;
        }

        if (!ans.equals("")) {
            return;
        }

        temp.append('0');
        solve(n, mp, temp);
        temp.deleteCharAt(temp.length() - 1);

        temp.append('1');
        solve(n, mp, temp);
        temp.deleteCharAt(temp.length() - 1);
    }

    public String findDifferentBinaryString(String[] nums) {

        HashMap<String, Integer> mp = new HashMap<>();
        int n = nums.length;

        for (int i = 0; i < n; i++) {
            mp.put(nums[i], 1);
        }

        StringBuilder temp = new StringBuilder();

        solve(n, mp, temp);

        return ans;
    }
}