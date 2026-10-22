class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length, first = nums[0];  // read the circle from the cut: no search for 0
        if (reads(nums, 0, n - first, first, 1) && reads(nums, n - first, n, 0, 1)) {  // counts up along the arrow
            int shift = (n - first) % n;  // where 0 sits
            return Math.min(shift, n - shift + 2);  // walk ahead, or turn, walk back, turn back
        }
        if (reads(nums, 0, first + 1, first, -1) && reads(nums, first + 1, n, n - 1, -1)) {  // counts up against the arrow
            int shift = first;  // where 0 sits
            return Math.min(shift + 2, n - shift);  // walk ahead and turn, or turn and walk back
        }
        return -1;
    }

    private boolean reads(int[] nums, int from, int to, int value, int step) {  // nums[from..to) is value, value + step, ...
        for (int k = from; k < to; k++, value += step)
            if (nums[k] != value) return false;
        return true;
    }
}