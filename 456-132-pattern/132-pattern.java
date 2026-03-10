class Solution {
    public boolean find132pattern(int[] nums) {
        int n=nums.length;
        Stack<Integer> st = new Stack<>();
        int third = Integer.MIN_VALUE;

        int i = n - 1;

        while(i >= 0)
        {
            if(nums[i] < third)
            {
                return true;
            }

            while(!st.isEmpty() && nums[i] > st.peek())
            {
                third = st.pop();
            }

            st.push(nums[i]);

            i--;
        }

        return false;
    }
}