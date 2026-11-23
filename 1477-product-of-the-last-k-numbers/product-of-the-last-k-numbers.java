class ProductOfNumbers {
    private final int[] prefix = new int[40001];
    private int size = 0;

    public ProductOfNumbers() {
        prefix[0] = 1; // Sentinel value to simplify division
    }
    
    public void add(int num) {
        if (num == 0) {
            size = 0; // Reset pointer in O(1) without clearing memory
        } else {
            size++;
            prefix[size] = prefix[size - 1] * num;
        }
    }
    
    public int getProduct(int k) {
        if (k > size) {
            return 0;
        }
        return prefix[size] / prefix[size - k];
    }
}
