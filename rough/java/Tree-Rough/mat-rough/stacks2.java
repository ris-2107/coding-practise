import java.util.ArrayDeque;
import java.util.Stack;

public class stacks2 {
    public static void main(String[] args) {
        int[] a = { 1, 2, 13, 40, 25, 79 };
        // System.out.println("Hi");
        stockSpanI(a);
        stockSpan(a);
    }

    public static void stockSpanI(int[] arr) {
        int n = arr.length;
        System.out.print("Span: ");
        for (int i = 0; i < n; i++) {
            int span = 1;
            for (int j = i - 1; j >= 0 && arr[j] <= arr[i]; j--) {
                span++;
            }

            System.out.print(span + " ");
        }
    }

    public static void stockSpan(int[] arr) {

        int n = arr.length;
        Stack<Integer> s = new Stack<>();
        s.push(0);
        System.out.print(1);
        int span = 0;

        for (int i = 1; i < n; i++) {
            // remove all the smaller and equal items from the stack:
            while (s.isEmpty() == false && arr[s.peek()] <= arr[i]) {
                s.pop();
            }
            span = s.isEmpty() ? i + 1 : i - s.peek();
            System.out.print(span);
            s.push(i);
        }
    }

}
