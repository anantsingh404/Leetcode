class comp implements Comparator<Integer>{
     public int compare(Integer x, Integer y) {

        int bx = Integer.bitCount(x);
        int by = Integer.bitCount(y);

        if (bx != by) {
            return bx - by;
        }

        return x - y;
    }
}
class Solution {
    public int[] sortByBits(int[] arr) {
         Integer[] a = new Integer[arr.length];
         for(int i=0;i<arr.length;i++)
         {
            a[i]=arr[i];
         }
        Arrays.sort(a, new comp());
         int i = 0;
        while (i < arr.length) {
            arr[i] = a[i];
            i++;
        }

        return arr;
    }
}