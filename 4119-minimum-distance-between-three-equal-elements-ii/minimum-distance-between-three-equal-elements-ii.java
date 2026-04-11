class Solution {
    public int minimumDistance(int[] nums) {
       int n = nums.length;

    HashMap<Integer, Integer> mp1 = new HashMap<>();
    HashMap<Integer, Integer> mp2 = new HashMap<>();

    int j = 0;
    int ans = Integer.MAX_VALUE;

    int i = 0;

    while (i < n) {

        // add element
        mp1.put(nums[i], mp1.getOrDefault(nums[i], 0) + 1);

        // if freq becomes 3 → mark in mp2
        if (mp1.get(nums[i]) == 3) {
            mp2.put(nums[i], 1);
        }

        // shrink if violation
        while (!mp2.isEmpty()) {

            // ❗ try to calculate answer
            if (mp1.get(nums[i]) >= 3) {
                int dist = 2 * (i - j);
                if (dist < ans) {
                    ans = dist;
                }
            }

            // remove from left
            mp1.put(nums[j], mp1.get(nums[j]) - 1);

            if (mp1.get(nums[j]) == 2) {
                mp2.remove(nums[j]);
            }

            if (mp1.get(nums[j]) == 0) {
                mp1.remove(nums[j]);
            }

            j++;
        }

        i++;
    }

    if (ans == Integer.MAX_VALUE) {
        return -1;
    }

    return ans; 
    }
}