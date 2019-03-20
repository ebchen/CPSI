
import java.util.*;
import java.io.*;

public class duel {

    public static int essays;
    public static int relations;
    public static ArrayList<Integer>[] adjacency;
    public static int[] indegree;
    public static ArrayList<Integer> output;

    public static int topSort() {
        boolean[] visited = new boolean[essays];
        ArrayDeque<Integer> zero = new ArrayDeque<Integer>();
        boolean mult = false;

        for (int i = 0; i < indegree.length; i++) {
            if (indegree[i] == 0) {
                zero.addLast(i);
            }
        }

        if (zero.size() == 0) {
            return 0;
        }
        if (zero.size() > 1) {
            mult = true;
        }

        while (zero.size() > 0) {
            if (zero.size() > 1) {
                mult = true;
            }

            int x = zero.poll();

            visited[x] = true;
            for (int neighbor : adjacency[x]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    zero.addLast(neighbor);
                }
            }

        }

        for (int i = 0; i < visited.length; i++) {
            if (visited[i] == false) {
                return 0;
            }
            if (indegree[i] > 0) {
                return 0;
            }
        }
        if (mult) {
            return 2;
        }
        return 1;

    }

    public static void main(String[] args) throws Exception {
        output = new ArrayList<Integer>();
        boolean terminate = false;
        Scanner scan = new Scanner(System.in);
        do {
            
            essays = scan.nextInt();
            relations = scan.nextInt();
            adjacency = new ArrayList[essays];
            indegree = new int[essays];
            for (int i = 0; i < adjacency.length; i++) {
                adjacency[i] = new ArrayList<Integer>();
            }

            if (essays == 0 && relations == 0) {
                terminate = true;
                continue;
            }

            for (int i = 0; i < relations; i++) {
                int d = scan.nextInt();
                int u = scan.nextInt();

                adjacency[d - 1].add(u - 1);
                indegree[u - 1]++;
            }

            System.out.println(topSort());

        } while (terminate == false);

    }

}