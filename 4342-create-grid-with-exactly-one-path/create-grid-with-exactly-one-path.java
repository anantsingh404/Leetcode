class Solution {
    public String[] createGrid(int m, int n) {
          String[] arr = new String[m];
        
        // 1. Build the default row: ".###..." (Length n)
        StringBuilder defaultBuilder = new StringBuilder(n);
        defaultBuilder.append('.');
        for (int i = 1; i < n; i++) {
            defaultBuilder.append('#');
        }
        String defaultRow = defaultBuilder.toString();
        
        // 2. Build the special last row: "......" (Length n)
        StringBuilder dotsBuilder = new StringBuilder(n);
        for (int j = 0; j < n; j++) {
            dotsBuilder.append('.');
        }
        String dotsRow = dotsBuilder.toString();
        
        // 3. Populate the array using pre-built string references
        for (int i = 0; i < m; i++) {
            if (i == m - 1) {
                arr[i] = dotsRow;
            } else {
                arr[i] = defaultRow;
            }
        }
        
        return arr;
    }
}