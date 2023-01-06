
public class a1 {
    public static void main(String[] args) {
        int a[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
        rotate90(a);
        printArr(a);
    }

    static void printArr(int[][] a) {
        for (int i = 0; i < a.length; i++) {
            for (int j = 0; j < a.length; j++) {
                System.out.print(a[i][j] + " ");
            }
            System.out.println();
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

        for( int )
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
