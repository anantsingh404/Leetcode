class Solution {
    void solve(int idx, int n, int count, List<Integer> temp, List<List<Integer>> ls)
    {
        if(count == 0)
        {
            ls.add(new ArrayList<>(temp));
            return;
        }

        if(idx > n)
        {
            return;
        }

        // take
        temp.add(idx);
        solve(idx + 1, n, count - 1, temp, ls);
        temp.remove(temp.size() - 1);

        // not take
        solve(idx + 1, n, count, temp, ls);
    }

    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ls = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        solve(1, n, k, temp, ls);
        return ls;
    }
}