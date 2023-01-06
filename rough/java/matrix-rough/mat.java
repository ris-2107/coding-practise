import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

class mat {
    public static void main(String[] args) {
        System.out.println("Hi");
        int arr[][] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

        printArr(arr);

    }

    public static void printArr(int[][] arr) {
        System.out.println(arr.length);
        System.out.println(arr[0].length);
    }
}
