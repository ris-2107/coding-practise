
public class a1 {
    public static void main(String[] args) {
        int a[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
        // rotate90Transpose(a);
        // printSpiral(a);
        


        // printArr(a);
        // System.out.println("\n");
        // int b[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14,
        // 15, 16 } };
        // rotate90(b);
        // printArr(b);
    }

    static void printArr(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
        }
    }

    static int searchElem(int[][] arr, int x) {
        int R = arr.length;
        int C = arr[0].length;
        int i = 0;
        int j = C - 1;

        while (i < R && j >= 0) {
            if (x == arr[i][j]) {
                return x;
            }
            if (arr[i][j] > x)
                j--;
            else
                i++;
        }
        return -1;

    }

    static void printSpiral(int[][] arr) {

        int top = 0, left = 0;
        int right = arr[0].length - 1;
        int bottom = arr.length - 1;

        while (top <= bottom && right >= left) {

            for (int i = left; i <= right; i++)
                System.out.print(arr[top][i] + " ");
            top++;

            // right column:
            for (int i = top; i <= bottom; i++)
                System.out.print(arr[i][right] + " ");
            right--;

            // bottom row reverse:
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    System.out.print(arr[bottom][i] + " ");
                }
            }
            bottom--;

            // left column reverse:
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    System.out.print(arr[i][left] + " ");
            }
            left++;
        }
    }

    static void rotate90(int[][] arr) {
        int n = arr.length;
        int[][] temp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[n - j - 1][i] = arr[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = temp[i][j];
            }
        }

    }

    static void rotate90Transpose(int[][] arr) {
        int n = arr.length;
        // 1. Make the Transpose:
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(i, j, arr);
            }
        }

        // 2. Reverse Each Column:

        for (int i = 0; i < n; i++) {
            int high = n - 1;
            int low = 0;
            int temp;
            while (high > low) {
                temp = arr[low][i];
                arr[low][i] = arr[high][i];
                arr[high][i] = temp;
                low++;
                high--;
            }
        }
    }

    static void doTranspose(int[][] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                swap(i, j, arr);
            }
        }

    }

    static void swap(int i, int j, int[][] arr) {
        int temp = arr[i][j];
        arr[i][j] = arr[j][i];
        arr[j][i] = temp;
    }
}
