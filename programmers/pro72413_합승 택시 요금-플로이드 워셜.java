import java.io.IOException;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IOException {
        Solution solution = new Solution();
        int[][] arr = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};

        solution.solution(6,4,6,2, arr);
    }
}

class Solution {
    public int solution(int n, int s, int a, int b, int[][] fares) {
        s--;
        a--;
        b--;

        for (int[] fare : fares) {
            fare[0]--;
            fare[1]--;
        }

        Route route = new Route(n, fares);

        int min = route.getFare(s, a) + route.getFare(s, b);

        for (int mid = 0; mid < n; mid++) {
            int cost = route.getFare(s, mid) + route.getFare(mid, a) + route.getFare(mid, b);
            if (min > cost) {
                min = cost;
            }
        }

        int answer = min;
        return answer;
    }
}

class Route {
    static final int MAX = 1000000 * 200 + 123456789;

    int n;
    int[][] map;
    int[][] fares;

    public Route(int n, int[][] fares) {
        this.n = n;
        this.map = new int[n][n];
        this.fares = fares;

        initMap();
        calculateFares();
    }

    private void initMap() {
        for (int[] arr : map) {
            Arrays.setAll(arr, operand -> {
                return MAX;
            });
        }

        for (int i = 0; i < n; i++) {
            map[i][i] = 0;
        }


        for (int[] fare : fares) {
            int from = fare[0];
            int to = fare[1];
            int cost = fare[2];

            map[from][to] = cost;
            map[to][from] = cost;
        }
    }

    private void calculateFares() {
        for (int k = 0; k < n; k++) {
            for (int from = 0; from < n; from++) {
                for (int to = 0; to < n; to++) {
                    if (map[from][k] + map[k][to] < map[from][to]) {
                        map[from][to] = map[from][k] + map[k][to];
                    }
                }
            }
        }
    }

    public int getFare(int from, int to) {
        return map[from][to];
    }
}
