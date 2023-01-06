import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

class myHash {
    // declaration
    int[] arr;
    int cap, size;

    myHash(int c) {
        cap = c;
        size = 0;
        // initialization
        arr = new int[c];
        arr[0] = 5;
        for (int i = 1; i < cap; i++) {
            arr[i] = -1;
        }
    }

    int hash(int key) {
        return (key % cap);
    }

    // count the distinct frequencies:

    static void countDistinct() {
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        int[] a = { 1, 2, 2, 290, 290, 2, 3, 4, 4, 4, 4, 4, 5, 1, 2, 3, 3, 3, 3, 3, 3, 3, 33, 3, 3 };
        for (int x : a) {
            map.put(x, map.getOrDefault(x, 0) + 1);
        }

        for (HashMap.Entry<Integer, Integer> entry : map.entrySet()) {
            System.out.println("Number =\t " + entry.getKey() + "\t  Frequency = " + entry.getValue());
        }
    }

    static int countIntersection(int[] a, int[] b) {

        HashSet<Integer> set = new HashSet<>();

        for (int x : a) {
            set.add(x);
        }
        int res = 0;
        for (int x : b) {
            if (set.contains(x)) {
                res++;
                set.remove(x);
            }
        }
        return res;

    }

    static int findUnion(int[] a, int[] b) {

        HashSet<Integer> set = new HashSet<>();
        for (int x : a) {
            set.add(x);
        }
        for (int x : b) {
            set.add(x);
        }
        return set.size();
    }

    static boolean getSumPresent(int[] a, int sum) {

        HashSet<Integer> s = new HashSet<>();
        for (int x : a) {
            if (s.contains((sum - x))) {
                return true;
            }
            s.add(x);
        }
        return false;
    }

    static boolean subArrWithZeroSum(int[] a) {

        int PRE_SUM = 0;

        HashSet<Integer> set = new HashSet<>();
        for (int ele : a) {
            PRE_SUM += ele;

            // Important condition:
            if (PRE_SUM == 0) {
                return true;
            }
            if (set.contains(PRE_SUM)) {
                return true;
            }

            set.add(PRE_SUM);
        }
        return false;

    }

    static boolean subArrayWithGivenSum(int a[], int sum) {
        HashSet<Integer> set1 = new HashSet<>();
        int PRE_SUM = 0;

        for (int x : a) {
            PRE_SUM += x;
        }

        for (int x : a) {

            if (sum == PRE_SUM) {
                return true;
            }

            if (set1.contains(PRE_SUM - sum)) {
                return true;
            }

            set1.add(PRE_SUM);
        }

        return false;
    }

    public static void main(String[] args) {
        Integer[] arr = { 1, 2, 3, 4, 9, 9, 9, 0, 8, 9, 8, 9, 89, 7, 7, 78, 9, 5 };
        int a[] = { 1, 2, -3, 2, 3, 4, 11 };
        int b[] = { 1, 2, 4, 7, 1 };
        // HashSet<Integer> set = new HashSet<>(Arrays.asList(arr));
        // System.out.println("No. of distinct values = " + set.size());
        // countDistinct();

        // System.out.println(countIntersection(a, b));
        // System.out.println("\nProgram Output: \n ");
        // System.out.println(findUnion(a, b));
        System.out.println("Ans: " + subArrayWithGivenSum(b, 7));

    }

}