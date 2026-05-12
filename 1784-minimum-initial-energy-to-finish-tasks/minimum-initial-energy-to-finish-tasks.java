class Solution 
{
    private boolean check(int energy, int[][] tasks)
    {
        int curr = energy;

        int i = 0;

        while(i < tasks.length)
        {
            int actual = tasks[i][0];
            int minimum = tasks[i][1];

            if(curr < minimum)
            {
                return false;
            }

            curr = curr - actual;

            i++;
        }

        return true;
    }

    public int minimumEffort(int[][] tasks) 
    {
        Arrays.sort(tasks, new Comparator<int[]>() 
        {
            @Override
            public int compare(int[] a, int[] b) 
            {
                int diff1 = a[1] - a[0];
                int diff2 = b[1] - b[0];

                // Sort by (minimum - actual) in descending order
                return diff2 - diff1;
            }
        });

        int low = 1;
        int high = 0;

        int i = 0;

        while(i < tasks.length)
        {
            high = high + tasks[i][1];
            i++;
        }

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(check(mid, tasks) == true)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
}