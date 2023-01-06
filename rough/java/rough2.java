import java.util.*;

public class rough2 {

    static boolean isgivenSumPresent(int a[], int sum) {
        HashSet<Integer> set = new HashSet<>();
        int PREFIX_SUM = 0;

        for (int ele : a) {
            PREFIX_SUM += ele;
            if (PREFIX_SUM == sum)
                return true;

            if (set.contains(PREFIX_SUM + sum))
                return true;

            set.add(PREFIX_SUM);
        }

        return false;
    }

    public static void main(String[] args) {

        int[] a = { 1, 2, 3, 4, 7, 8, 90 };
        System.out.println("Answer " + isgivenSumPresent(a, 10));

    }
}
