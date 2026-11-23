class ProductOfNumbers {
    private List<Integer> ls;

    public ProductOfNumbers() {
        ls = new ArrayList<>();
    }
    
    public void add(int num) {
        if (num == 0) 
        {
            ls.clear();
        } 
        else if (!ls.isEmpty()) {
            ls.add(ls.get(ls.size() - 1) * num);
        }
         else
         {
            ls.add(num);
        }
    }
    
    public int getProduct(int k) {
        int n = ls.size();
        
        if (k > n) {
            return 0;
        }
        if (k == n) {
            return ls.get(n - 1);
        }
        return ls.get(n - 1) / ls.get(n - 1 - k);
    }
}
