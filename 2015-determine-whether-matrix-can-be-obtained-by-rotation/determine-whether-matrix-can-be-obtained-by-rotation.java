class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;

        // check original (0 degree)
        if(check(mat, target)) {
            return true;
        }

        int k = 0;
        while(k < 3) {
            rotate(mat, n); // 90 degree
            if(check(mat, target)) {
                return true;
            }
            k++;
        }

        return false;
    }

    boolean check(int[][] a, int[][] b) {
        int n = a.length;
        int i = 0;
        while(i < n) {
            int j = 0;
            while(j < n) {
                if(a[i][j] != b[i][j]) {
                    return false;
                }
                j++;
            }
            i++;
        }
        return true;
    }

    void rotate(int[][] mat, int n) {
        // transpose
        int i = 0;
        while(i < n) {
            int j = i + 1;
            while(j < n) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
                j++;
            }
            i++;
        }

        // reverse rows
        int r = 0;
        while(r < n) {
            int l = 0;
            int h = n - 1;
            while(l < h) {
                int temp = mat[r][l];
                mat[r][l] = mat[r][h];
                mat[r][h] = temp;
                l++;
                h--;
            }
            r++;
        }
    }
}