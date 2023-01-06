import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;

class myHashing {

    static int getLongestSubArray(int[] a, int sum) {
        int res = 0;
        int PREFIX_SUM = 0;

        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < a.length; i++) {
            PREFIX_SUM += a[i];
            if (PREFIX_SUM == sum) { // checking the special base condition
                res = i + 1;
            }
            if (!map.containsKey(PREFIX_SUM)) { // populate hashmap only when the PS is not already present:
                map.put(PREFIX_SUM, i);
            }
            if (map.containsKey(PREFIX_SUM - sum)) { // checking if the required sum id present
                res = Math.max(res, i - map.get((PREFIX_SUM - sum)));
            }
        }
        return res;
    }

    static int getLongestSubArrayWithEqualBinaries(int[] a) {

        int res = 0;
        int PREFIX_SUM = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < a.length; i++) {
            if (a[i] == 0) {
                PREFIX_SUM += -1;
            } else {
                PREFIX_SUM += 1;
            }
            if (PREFIX_SUM == 0) {
                res = i + 1;
            }
            if (!map.containsKey(PREFIX_SUM)) {
                map.put(PREFIX_SUM, i);
            }
            if (map.containsKey(PREFIX_SUM)) {
                res = Math.max(res, i - map.get((PREFIX_SUM)));
            }
        }
        return res;

    }

    static int getLongestSpan(int[] a, int[] b) {
        int res = 0;
        int sumA = 0;
        int sumB = 0;

        // iterative solution - Naive
        for (int i = 0; i < a.length; i++) {

            for (int j = 0; j < b.length; j++) {
                sumA += a[j];
                sumB += b[j];
                if (sumA == sumB) {
                    res = Math.max(res, i - j + 1);
                }
            }
        }

        return res;
    }

    static int getLongestBinarySpanOfTheArray(int[] a, int b[]) {
        // declaration
        int[] temp = new int[a.length];
        int res = 0;

        // initialization
        for (int i = 0; i < a.length; i++) {
            temp[i] = a[i] + b[i];
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        int PREFIX_SUM = 0;
        for (int i = 0; i < a.length; i++) {
            PREFIX_SUM += temp[i];
            if (PREFIX_SUM == 0) {
                return i + 1;
            }
            if (!map.containsKey(PREFIX_SUM)) {
                map.put(PREFIX_SUM, i);
            }
            if (map.containsKey(PREFIX_SUM)) {
                return (Math.max(res, i - map.get(PREFIX_SUM)));
            }
        }
        return res;
    }

    static int lengthOfLongestSubsequenceIterative(int a[]) {

        // Iterative
        // Time Complexity : O(n log n) | space complexity: O(n)
        int res = 1;
        int current = 0;
        Arrays.sort(a);
        for (int i = 1; i < a.length; i++) {
            if (a[i] - a[i - 1] == 1) {
                current++;
            } else {
                res = Math.max(res, current);
            }
        }

        return Math.max(res, current);
    }

    static int lengthOfLongestSubsequenceHash(int a[]) {
        int res = 1;
        int current = 0;

        HashSet<Integer> set = new HashSet<Integer>();
        for (int x : a) {
            set.add(x);
        }
        for (int i = 0; i < a.length; i++) {

            if (!set.contains(a[i] - 1)) {
                // means it is the starting point
                current = 1;

                while (set.contains(a[i] + current)) {

                    current++;
                }
            }
            res = Math.max(res, current);

        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = { 1, 9, 3, 4, 2, 10, 11, 12, 14, 15, 16, 17, 18, 13 };
        System.out.println("ANS: " + lengthOfLongestSubsequenceHash(arr));
    }
}