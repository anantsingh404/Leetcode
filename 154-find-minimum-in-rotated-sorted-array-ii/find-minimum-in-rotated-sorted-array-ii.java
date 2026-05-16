class Solution {
    public int findMin(int[] nums) {
          int low = 0;
        int high = nums.length - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                // Minimum is in the right unsorted part
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                // Minimum is at mid or to its left
                high = mid;
            } else {
                // Duplicates encountered; safely shrink the search space
                high--;
            }
        }
        return nums[low];
    }
}