import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public static int[] rankTeams(String[] votes) {

        // Base conditions:
        if (votes.length == 0)
            return null;

        // if (votes.length == 1)
        // return votes[0];

        // Program Logic :
        HashMap<Character, int[]> map = new HashMap<Character, int[]>();
        for (String vote : votes) {
            int[] temp = new int[vote.length()];
            ArrayList<Integer> list = new ArrayList<Integer>(vote.length());
            int i=0;
            for (; i < vote.length(); i++) {
                list.add(i+1);
               
            }
            map.put(vote.charAt(i), temp);
            return temp;
            // temp = null;
        }
        return null;
    }

    public int getSumOfArray(int[] a) {
        int sum = 0;
        for (int x : a) {
            sum += x;
        }
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("The OP");
        String[] teams = { "ABCD" };
        int[] ans = rankTeams(teams);
        for (int x : ans) {
            System.out.println("-> " + x);
        }
    }
}