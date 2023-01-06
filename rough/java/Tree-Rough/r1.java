import java.util.LinkedList;
import java.util.Queue;

class Node {
    int value;
    Node left;
    Node right;

    Node(int value) {
        this.value = value;
        right = null;
        left = null;
    }
}

public class r1 {

    public void printLevelOrder(Node root) { // S/C = O(n)

        // base case:
        if (root == null)
            return;
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);

        while (!q.isEmpty()) {
            Node curr = q.poll();

            System.out.println(curr.value);

            if (curr.left != null) {
                q.add(curr.left);
            }
            if (curr.right != null) {
                q.add(curr.right);
            }
        }

    }

    private void levelOrderLineByLine(Node root) {
        if (root == null)
            return;

        Queue<Node> q = new LinkedList<Node>();

        q.add(root);
        q.add(null);

        while (q.size() > 1) {
            Node curr = q.poll();
            if (curr == null) {
                System.out.println("");
                q.add(null);
                continue;
            }
            System.out.print(curr.value + " ");

            if (curr.left != null) {
                q.add(curr);
            }
            if (curr.right != null) {
            }

        }

    }
}
