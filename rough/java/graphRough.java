import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

// this program is to implement BFS:
class Test {
    static void addEdge(ArrayList<ArrayList<Integer>> adj, int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);

    }

    static void printGraph(ArrayList<ArrayList<Integer>> adj) {
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj.get(i).size(); j++) {
                System.out.println(adj.get(i).get(j) + " ");
            }
            System.out.println();
            ;
        }
    }

    static void bfsTraversal(ArrayList<ArrayList<Integer>> adj, int v, int s, boolean[] visited) {

        Queue<Integer> q = new LinkedList<Integer>();
        visited[s] = true;
        q.add(s);

        while (!q.isEmpty()) {
            int u = q.poll();
            System.out.print(u + " ");
            for (int x : adj.get(u)) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.add(x);
                }
            }
        }

    }

    public static void main(String[] args) {

        System.out.println("Enter the Number of vertices");
        Scanner sc = new Scanner(System.in);
        int v = 5;

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(v);
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<Integer>());
        }
        // for (int i = 0; i < v; i++) {
        // System.out.println("Enter source");
        // int src = sc.nextInt();
        // System.out.println("Enter destination");
        // int des = sc.nextInt();

        // addEdge(adj, src, des);

        // }

        addEdge(adj, 0, 1);
        addEdge(adj, 0, 2);
        addEdge(adj, 1, 2);
        addEdge(adj, 1, 3);

        addEdge(adj, 2, 3);
        addEdge(adj, 2, 4);

        printGraph(adj);
        boolean visited[] = new boolean[v + 1];
        int count = 0;
        for (int i = 0; i < v; i++) {
            if (!visited[v]) {
                bfsTraversal(adj, v, i, visited);
                count++;
            }
        }

        System.out.println("The number of connected components = ");

    }

}